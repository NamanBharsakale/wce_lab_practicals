#include <iostream>
using namespace std;

int CalculateSquare(int x)
{
    return x * x;
}

class ProblemSolution
{
    public:
    int Solution(int N){
        int (*funcPtr) (int) = CalculateSquare;
        return funcPtr(N);
    }
};

int main()
{
    ProblemSolution obj;
    int result = obj.Solution(5);
    cout<<result<<endl;
    return 0;
}

