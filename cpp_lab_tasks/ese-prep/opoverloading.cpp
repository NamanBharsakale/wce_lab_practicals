#include <iostream>
using namespace std;

class Complex{
    int real,imag;
    public:
    Complex(int r = 0, int i = 0){
        real = r;
        imag = i;
    }

    void display(){
        cout<<"Real : "<<real<<endl;
        cout<<"Imag: "<<imag<<endl;
    }

    Complex operator + (Complex &c){
        Complex d;
        d.real = this->real + c.real;
        d.imag = this->imag + c.imag;
        return d;
    }
};

int main(){

    Complex a(4,5.5);
    a.display();

    Complex b(10,4.5);
    b.display();

    Complex c =  a + b;
    c.display();
}