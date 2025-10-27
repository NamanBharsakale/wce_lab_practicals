#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the "<<n<<" elements : ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    //Insertion Sort
    for(int k = 1; k < n; k++){
        int temp = arr[k];
        int ptr = k - 1;

        while(ptr > 0 && temp < arr[ptr]){
            arr[ptr + 1] = arr[ptr];
            ptr = ptr - 1;
        }
        arr[ptr + 1] = temp;
    }

    //Sorted array
    cout<<"Sorted array: ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}