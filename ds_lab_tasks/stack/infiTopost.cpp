#include <iostream>
#include <string.h>
using namespace std;

#define MAX 10

class Stack{
    public:
    char a[MAX];
    int top;
    public:
    Stack(){
        top = -1;
    }

    void push(char c){
        if(top == MAX - 1){
            cout<<"Stack full..";
            return;
        }

        a[++top] = c;
    }

    char pop(){
        if(top == -1){
            cout<<"Stack is empty..";
            return '\0';
        }

        return a[top--];
    }

    char peek(){
        if(top == -1){
            cout<<"Stack is empty..";
            return '\0';
        }
        
        return a[top];
    }

    bool isEmpty(){
        return top == -1;
    }
};

bool isOperator(char c){
    if(c == '+' || c == '-' || c == '/' || c == '*' || c == '^'){
        return true;
    }
    return false;
}

bool isOperand(char c){
    if((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z')||(c >= '0' && c <= '9')){
        return true;
    }
    return false;
}

int precedence(char c){
    if(c == '^') {
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '-' || c == '+'){
        return 1;

    }
    else{
        return 0;
    }
}
void postFix(char inf[], char post[]){
    int n = strlen(inf);

    Stack s;
    int j = 0;

    for(int i = 0; i < n; i++){

        char c = inf[i];


        if(isOperand(c)){
            post[j++] = c;
        }
        else if(c == '('){
            s.push(c);
        }
        else if(c == ')'){
            while(!s.isEmpty() && s.peek() != '('){
                post[j++] = s.pop();
            }
            s.pop();
        }
        else if(isOperator(c)){
            while(!s.isEmpty() && precedence(s.peek()) >= precedence(c)){
                post[j++] = s.pop();
            }
            s.push(c);
        }
    }


    while(!s.isEmpty()){
        post[j++] = s.pop();
    }

    post[j] = '\0';

    cout<<"Postfix: "<<post;
} 

void reverse(char inf[]){
    int n = strlen(inf);
    for(int i = 0; i < n/2; i++){
       char c = inf[i];
       inf[i] = inf[n - i - 1];
       inf[n - i - 1] = c;
    }
}
void prefix(char inf[]){
    reverse(inf);

    int n = strlen(inf);
    for(int i = 0; i < n; i++){
        if(inf[i] == '('){
            inf[i] = ')';
        }
        else if(inf[i] == ')'){
            inf[i] = '(';
        }
    }

    char post[100];
    postFix(inf,post);

    reverse(post);
    cout<<"Prefix: "<<post;
}
int main()
{
    char inf[30];
    cout<<"Enter the infix expression: ";
    cin>>inf;

    prefix(inf);

    return 0;
}