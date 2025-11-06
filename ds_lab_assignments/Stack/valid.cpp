#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100
class Stack{
    public:
    int top;
    int a[MAX];

    public:
    Stack(){
        top = -1;
    }

    void push(int val){
        if(top == MAX -1){
            cout<<"stack is full";
            return;
        }

        a[++top] = val;
    }

    void pop(){
        if(top == -1){
            cout<<"Stack is empty..";
            return;
        }

        a[top--];
    }
    int peek(){
        if(top == -1){
            return -1;
        }


        return a[top];
    }

    bool isEmpty(){
        return top == -1;
    }
};


int validParan(char* str){
    Stack s;
    int n = strlen(str);
    int maxLen = 0;
    for(int i = 0; i < n ; i++){
        if(str[i] == '('){
            s.push(i);
        }
        else{
            s.pop();
            if(s.isEmpty()){
                s.push(i);
            }
            else{
                int len = i - s.peek();
                if(len > maxLen){
                    maxLen = len;
                }
            }
        }
    }

    return maxLen;
}

int main(){
    char s[100];
    cout<<"Enter the string: ";
    cin>>s;


    cout<<"Longest valid paranthessi: "<<validParan(s);

    return 0;
}