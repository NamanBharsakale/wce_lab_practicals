#include <iostream>
#include <cstring>
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

bool isSame(char open, char close){
    if(open == '(' && close == ')') return true;
    else if(open == '{' && close == '}') return true;
    else if(open == '[' && close == ']') return true;

    return false;
}
bool validFormula(char* f){
    Stack s;
    int n = strlen(f);

    for(int i =0 ; i < n ; i++){
        if(f[i]=='(' || f[i] == '[' || f[i] == '{'){
            s.push(f[i]);
        }
        else if(f[i] == ')' || f[i] == ']' || f[i] == '}'){
            if(s.isEmpty()){
                return false;
            }
            char top = s.pop();
            if(isSame(top,f[i])){
                return true;
            }
            else {
                return false;
            }
        }    
    }
}
int main(){

    char f[90];
    cout<<"Enter the formula: ";
    cin>>f;

    if(validFormula(f)){
        cout<<"yes . valid";

    }
    else{
        cout<<"Not valid..";
    }

    return 0;
}