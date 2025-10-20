#include <iostream>
using namespace std;

void Solution(int* P1, int* P2)
{
    int t = *P1;
    *P1 = *P2;
    *P2 = t;
}

int main()
{
    int a = 5, b = 6;


    Solution(&a,&b);
    cout<<a<<" "<<b<<endl;

    return 0;

}