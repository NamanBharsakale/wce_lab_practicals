#include <iostream>
using namespace std;

class Shape{
    public:
    virtual void calculateArea() = 0;
};

class Rectangle: public Shape{
    int l,b;
    public:
    Rectangle(int l , int b){
        this->l = l;
        this->b = b;
    }
    void calculateArea() override{
        int a = l * b;
        cout<<"Rectangle area is "<<a<<endl;
    }
};

class Square: public Shape{
    int side;
    public:

    Square(int s){
        side = s;
    }
    void calculateArea() override{
        int a = side * side;
        cout<<"Area of Square: "<<a<<endl;
    }
};
int main(){
    Shape* s = new Square(5);
    Shape* p = new Rectangle(3,4);

    s->calculateArea();
    p->calculateArea();

    delete s;
    delete p;
    return 0;

}