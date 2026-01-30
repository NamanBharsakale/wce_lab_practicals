#include <iostream>
using namespace std;

int main(){
    int n,item;
    cout<<"How many elements you want to store: ";
    cin>>n;

    int a[n];

    cout<<"Enter "<<n<<" elements: ";
    for(int i = 0; i < n ;i++){
        cin>>a[i];
    }

    cout<<"Enter value to search: ";
    cin>>item;
    int beg = 0, end = n - 1;
    int mid;

    int pos = -1;
    while(beg <= end){
        mid = (beg + end) / 2;
        if(a[mid] == item)
        {
            pos = mid;
            break;
        }
        else {
            if(a[mid] < item){
                beg = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
    }

    if(pos != -1){
        cout<<item<<" found at "<<pos;
    }
    else{
        cout<<item<<" not found..";
    }

    return 0;
}