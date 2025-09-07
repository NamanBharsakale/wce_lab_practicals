#include <iostream>
using namespace std;

void towerOfhanoi(int n, char beg, char aux, char end)
{
    if(n == 1)
    {
        cout<<"MOVE DISK 1 from "<<beg<<" to "<<end<<endl;
        return;
    }
    towerOfhanoi(n -1,beg,end,aux);
    cout<<"MOVE DISK "<<n<<" from "<<beg<<" to "<<end<<endl;
    towerOfhanoi(n-1,aux,beg,end);

}

int main()
{
    int n;
    cout<<"Enter number of disks: ";
    cin>>n;
    towerOfhanoi(n,'A','B','C');

}