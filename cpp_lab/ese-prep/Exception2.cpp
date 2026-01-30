#include <iostream>
using namespace std;

class Calculate{
    int a,b;
    public:
    void getData(){
        try{
            cout<<"ENter two numbers: ";
            cin>>a>>b;


            if(a < 0 || b < 0){
                throw "Negative Numbers are not allowed..";
            }
            else{
                int sum = a + b;
                cout<<"Sum is "<<sum;
            }
        }
        catch(const char *ch){
            cout<<"Error: "<<ch<<endl;
        }
    }
};
int main(){
    Calculate c;
    c.getData();

    return 0;
}