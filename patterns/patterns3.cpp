#include <iostream>
using namespace std;

int main()
{
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j < i + 1; j++)
            cout<<j;

        cout<<endl;

    }
}
/*
1
12
123
1234
12345*/