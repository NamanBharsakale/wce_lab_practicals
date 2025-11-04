#include <iostream>
using namespace std;

void heapify(int a[],int n, int i){
    if(i > n){
        return;
    }

    int largest = i;

    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && a[largest] < a[left]){
        largest = left;
    }

    if(right < n && a[largest] < a[right]){
        largest = right;
    }

    if(largest != i){
        int t = a[i];
        a[i]= a[largest];
        a[largest] = t;

        heapify(a,n,largest);
    }
}

void buildMaxheap(int a[],int n){
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(a,n,i);
    }
}
void heapSort(int a[],int n){
    buildMaxheap(a,n);


    for(int i = n - 1; i > 0; i--){
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        heapify(a,i,0);
    }
}

void displayArr(int a[],int n){
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int n; 
    cout<<"Enter the number of node : ";
    cin>>n;
    int a[n];
    cout<<"Enter "<<n<<" elements: ";
    for(int i = 0 ; i < n; i++){
        cin>>a[i];
    }

    cout<<"Original Array: ";
    displayArr(a,n);

    cout<<endl;
    heapSort(a,n);

    cout<<"Sorted array: ";
    displayArr(a,n);


    return 0;

}