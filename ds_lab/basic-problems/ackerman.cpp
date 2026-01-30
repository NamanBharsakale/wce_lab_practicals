#include <iostream>
using namespace  std;

int ack(int m, int n)
{
    cout<<endl;
    if(m == 0)
    {
        cout<<"("<<m<<","<<n<<")";
        return (n +1);
    }
    else if( m > 0 && n == 0)
        cout<<"("<<m<<","<<n<<")";
        return ack(m -1 ,1);
    }
    else if(m != 0 && n != 0)
    {
        cout<<"("<<m<<","<<n<<")";
        return ack(m-1,ack(m,n-1));
    }
}
int main()
{
    int n1,n2;
    cout<<"Enter two numbers: ";
    cin>>n1>>n2;

    cout<<""<<ack(n1,n2);

    return 0;
    
} // namespace  std:

