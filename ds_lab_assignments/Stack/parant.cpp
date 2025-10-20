#include <iostream>
using namespace std;
#define MAX 100

class Stack{
    public:
    int top;
    char arr[MAX];

    Stack(){
        top = -1;
    }

    void push(char val){
        if(top == MAX-1){
            cout<<"Overflow..";
            return;
        }
        top = top + 1;
        arr[top] = val;
    }

    bool isEmpty(){
        return top == -1;
    }
    void pop(){
        if(top == -1){
            cout<<"Underflow...";
            return;
        }
        top = top - 1;
    }

    void display(){
        for(int i = top; i> -1;i--){
            cout<<arr[i]<<" ";
        }
    }
    int peek() { 
    if (!isEmpty()) { 
        return arr[top]; 
    } 
    return -1;
    }
    int validparan(string str){
        int max_len = 0;
        push(-1);
        for(int i = 0; i<(int)str.size();i++){
            if(str[i] == '('){
                push(i);
            }else{ //that means we have got ")"
                pop();
                if(isEmpty()){
                    push(i);
                }
                else{
                    int len = i - peek();
                    if(len > max_len){
                        max_len = len;
                    }
                }
            }
        }
        return max_len;
    }

};
int main()
{
    Stack v;
    string str;
    cout<<"Enter the paranthesis: ";
    cin>>str;
    
    int result = v.validparan(str);
    cout<<"Total valid paranthesis "<<result;
    return 0;
    
}
