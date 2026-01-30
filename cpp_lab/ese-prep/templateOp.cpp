#include <iostream>
using namespace std;

template <class T>
class Operation{
    public:
    void add(T a,T b){
        cout<<"Addition: "<<a+b<<endl;
    }

    void sub(T a, T b){
        cout<<"Substraction: "<<a-b<<endl;
    }
};

int main(){
    Operation<int> o1;

    o1.add(12,23);
    o1.sub(33,12);

    Operation<float> o2;
    o2.add(1.2,32.3);
    o2.sub(32,33);

    Operation<string> o3;
    o3.add(string("A"),string("B"));

    return 0;
}