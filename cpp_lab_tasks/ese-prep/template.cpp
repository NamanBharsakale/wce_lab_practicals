#include <iostream>
#include <string>
using namespace std;

//Function template

template <typename T>
void sum(T a, T b){
    T c = a + b;
    cout<<"Sum is "<<c<<endl;
}

template <typename T>
void getMax(T a,T b){
    T c = a > b? a : b;
    cout<<"Greatest is "<<c<<endl;
}
int main(){
    sum(3,4);
    getMax(3,4);

    sum(4.5f,5.5f);
    getMax(4.5f,5.5f);

    sum(string("A"),string("B"));
    getMax(string("A"),string("B"));


    sum(12,45);

    return 0;


}