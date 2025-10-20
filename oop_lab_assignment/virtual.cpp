#include <iostream>
using namespace std;

class Base
{
    public:
    int var = 1;
    void display(){
        cout<<"Display method of base class: "<<var<<endl;
    }
};

class derived : public Base{
    public:
    int var2 = 1;
    virtual void display(){
        cout<<"Display method of derived class: "<<var2<<endl;
    }
};

int main(){
    
    derived d;
    Base p;
    d.display();
    derived *bptr = &p;
    bptr -> display();

    //  d.display();
    return 0;
}