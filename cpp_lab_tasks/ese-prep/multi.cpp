#include <iostream>
#include <string>
using namespace std;


class Person{
    int age;
    string name;

    public:
    Person(int a,string n){
        age = a;
        name = n;
    }

    void display(){
        cout<<"Age: "<<age;
        cout<<"Name: "<<name;
    }
};

class Result{
    int ma1,ma2,ma3;
    public:
    Result(int m1,int m2){
        ma1 = m1;
        ma2 = m2;
    }
    void display(){
        cout<<"M1: "<<ma1<<" M2: "<<ma2<<endl;
    }
};

class Student: public Person, Result{
    int s_id;
    public:
    Student(int age,string name,int m1,int m2,int id):Person(age,name),Result(m1,m2){
        s_id = id;
    }
    void show(){
        Person::display();
        Result::display();
        cout<<"Student id: "<<s_id;
    }

};

int main(){
    Student s(11,"Naman",45,56,10);

    s.show();

    return 0;
}