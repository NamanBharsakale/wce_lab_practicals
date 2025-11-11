#include <iostream>
using namespace std;
class Shape{
    public:
    void display(){
        cout<<"Base class constructor..";
    }
};

class Circle: public Shape{
    public:
    void displayDerive(){
        display();
        cout<<"Derived Class Constructor..";
    }
};
int main(){

    Shape s;
    s.display();

    Circle c;
    c.displayDerive();

    return 0;

}