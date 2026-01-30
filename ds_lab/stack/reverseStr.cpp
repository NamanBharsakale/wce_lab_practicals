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

    void reverse(Stack &s,string str){
        for(char c: str){
            s.push(c);
        }
        while(top!=-1)
        {
            cout<<arr[s.top--]<<"";
        
            
        }

    }

};
int main()
{
    Stack v;
    string str;
    
    cin>>str;  
    v.reverse(v,str);
    return 0;
}
