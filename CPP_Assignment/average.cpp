#include <iostream>
using namespace std;

class ProblemSolution
{
    public:

    static double* solution(int N1,int N2)
    {
        double* average = new double(((double)N1 + (double)N2)/2);
        return average;
    }
};

int main()
{
    int N1,N2;
    cin>>N1>>N2;

    double* result = ProblemSolution :: solution(N1,N2);
    cout<<*result<<endl;

    delete result;
    return 0;

}
