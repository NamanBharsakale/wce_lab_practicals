#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Stack{
    public:
    int a[MAX];
    int top;
    public:
    Stack(){
        top = -1;
    }

    void push(int c){
        if(top == MAX - 1){
            cout<<"Stack full..";
            return;
        }

        a[++top] = c;
    }

    int pop(){
        if(top == -1){
            cout<<"Stack is empty..";
            return -1;
        }

        return a[top--];
    }

    int peek(){
        if(top == -1){
            cout<<"Stack is empty..";
            return -1;
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

bool isDigit(char c){
    if(c >= '0' && c <= '9'){
        return true;
    }

    return false;
}
int evaluate(char post[]){
    Stack s;
    int n = strlen(post);
    int i = 0;
    while(i < n){
        char c = post[i];

        if(c == ' '){
            i++;
            continue;
        }

        if(isDigit(c)){
            int num = 0;
            while(i < n && isDigit(post[i])){
                num = num * 10 + (post[i] - '0');
                i++;
            }
            s.push(num);
            continue;
        }
        else if(isOperator(c)){
            int v2 = s.pop();
            int v1 = s.pop();

            switch(c){
                case '+': s.push(v1 + v2);break;
                case '-': s.push(v1 - v2);break;
                case '*': s.push(v1 *v2); break;
                case '/':s.push(v1/v2);break;
                case '^':{
                    int res = 1;
                    for(int i = 1; i <= v2; i++){
                        res = res * v1;
                    }
                    s.push(res);
                    break;
                }
            }
        }

        i++;




    }
    return s.pop();
    
}

int main(){

    char post[100];
    cout<<"Enter the postfix expression: ";
    cin.getline(post,100);

    cout<<evaluate(post);
    return 0;
}