#include <iostream>
using namespace std;

class ProblemSolution{
    int N1,N2,sum;
    public:
    ProblemSolution(int a , int b) { N1 = a; N2 = b; }
    void CalculateSum() { sum = N1 + N2;}
    void Print(){ cout<<"Sum: "<<sum; }
};

int main()
{
    ProblemSolution a(5,6);
    ProblemSolution* ptr = &a;
    ptr -> CalculateSum();
    ptr -> Print();

    return 0;
}