#include <iostream>
#include <string>
using namespace std;

class Person{
    int age;
    string name;
    public:
    void setdata(int a, string n){
        age = a;
        name = n;
    }

    void display(){
        cout<<"Age: "<<age<<endl;
        cout<<"Name:"<<name<<endl;
    }
};

class Citizen: public Person{
    string nationality;
    public:
    void setDetails(int a,string n, string nat){
        setdata(a,n);
        nationality = nat;
    }

    void showdata()
    {
        display();
        cout<<"Nationality: "<<nationality<<endl;
    }
};
int main(){
    Person p;
    p.setdata(11,"Sham");
    p.display();

    Citizen c;
    c.setDetails(12,"Ram","Indian");
    c.showdata();
}