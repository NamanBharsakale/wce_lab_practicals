#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"How many elements you want to store: ";
    cin>>n;

    int a[n];
    cout<<"Enter "<<n<<" elements: ";
    for(int i =0 ; i<n;i++){
        cin>>a[i];
    }

    //insertion sort

    for(int i = 1; i < n;i++){
        int t = a[i];
        int ptr = i - 1;

        while(ptr >= 0 && a[ptr] > t){
            a[ptr + 1] = a[ptr];
            ptr = ptr - 1;
        }
        a[ptr + 1] = t;
    }

    cout<<"Sorted array: ";

    for(int i =0 ; i<n;i++){
        cout<<" "<<a[i];
    }

    return 0;
}