#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack{
    int top;
    int arr[MAX];

    public:
    Stack(){
        top = -1;
    }

    void push(int c){
        if(top == MAX -1){
            cout<<"Overflow"<<endl;
            return;
        }
        top = top + 1;
        arr[top] = c;

    }
    void pop(){
        if(isEmpty()){
            cout<<"Underflow"<<endl;
            return;
        }
        top = top - 1;
    }

    int peek(){
        if(isEmpty()){
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        return top == -1;
    }

    int validparan(string str){
        int max_len =0;
        push(-1);
        for(int i=0; i<(int)str.size();i++){
            if(str[i] == '('){
                push(i);
            }
            else{
                pop();
                if(isEmpty()){
                    push(i);
                }
                else{
                    int len = i - peek();
                    if(len>max_len){
                        max_len = len;
                    }
                }
            }
        }
        return max_len;
    }
};
int main(){
    Stack v;
    string str;
    cin>>str;

    cout<<"Total valid paranthessit: "<<v.validparan(str);
    return 0;
}