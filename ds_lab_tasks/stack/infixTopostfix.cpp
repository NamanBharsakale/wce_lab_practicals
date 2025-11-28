#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100
class Stack{
    public:
    char arr[MAX];
    int top;

    public:
    Stack(){
        top = -1;
    }

    void push(char c){
        if(top == MAX -1){
            cout<<"Stack Overflow..";
            return;
        }
        arr[++top] = c;
    }

    char pop(){
        if(isEmpty()){
            cout<<"Stack underflow..";
            return '\0';
        }
        return arr[top--];
    }

    bool isEmpty(){
        return top == -1;
    }

    char peek(){
        return arr[top];
    }
};

int precedence(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isOperand(char c){
    return ((c >= 'a' &&  c <= 'z' ) || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

void infixTopostfix(string infix){
    if(infix == "") {
        cout<<"Empty expression";
        return;
    }
    int j = 0;
    Stack s;
    int n = infix.size();
    char postfix[MAX];

    for(int i = 0; i < n;i++){
        char c = infix[i];

        if(isOperand(c)){
            postfix[j++] = c;
        }
        else if(c == '('){
            s.push(c);

        }
        else if(c == ')'){
            while(!s.isEmpty() && s.peek() != '('){
                postfix[j++] = s.pop();
            }
            s.pop();
        }
        else if(isOperator(c)){
            while(!s.isEmpty() && precedence(s.peek()) >= precedence(c)){
                postfix[j++] = s.pop();
            }
            s.push(c);
        }
    }

    while(!s.isEmpty()){
        postfix[j++] = s.pop();
    }

    postfix[j] = '\0';
    cout<<"Postfix Expression: "<<postfix;
}

int main(){

    string infix;
    cout<<"Enter infix expression: ";
    cin>>infix;

    infixTopostfix(infix);

    return 0;
}