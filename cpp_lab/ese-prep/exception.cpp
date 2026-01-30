#include <iostream>
using namespace std;

int main(){
    try{
        int n1, n2;
        cout<<"ENter two number: "<<endl;
        cin>>n1>>n2;

        if(n2 == 0){
            throw "Cannot divide by zero.";
        }

    }
    catch(const char* ch){
        cout<<"Error: "<<ch;
    }
}