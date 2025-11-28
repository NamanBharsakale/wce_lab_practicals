#include <iostream>
using namespace std;

class Shape{
    public:
    virtual void draw(){
        cout<<"Shape is drawing..";
    }
};

class Circle: public Shape{
    public:
    void draw() override{
        cout<<"Circle is drawing.."<<endl;
    }
};

class Rectangle : public Shape{
    public:
    void draw() override{
        cout<<"Rectangle is drawing.."<<endl;
    }
};

int main(){
    Shape* s;

    Circle c;
    c.draw();
    Rectangle r;
    r.draw();

    s = &c;
    s->draw();

    s = &r;
    s->draw();
}