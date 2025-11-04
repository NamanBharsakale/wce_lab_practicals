#include <iostream>
using namespace std;

int main() {
    int n,item;

    cout<<"How many elements you want to store: ";
    cin>>n;

    int a[n];

    cout<<"Enter "<<n<<" elements: ";
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    cout<<"Enter the value to search : ";
    cin>>item;

    int pos = -1;
    for(int i = 0; i < n; i++){
        if(a[i] == item){
            pos = i;
        }
    }

    if(pos != -1)
    {
        cout<<item<<" found at "<<pos;
    }
    else{
        cout<<item<<" not found";
    }

    return 0;


}
