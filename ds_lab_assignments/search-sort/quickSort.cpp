#include <iostream>
using namespace std;

int partition(int arr[],int low,int high){
    int p = arr[low];
    int i = low + 1;
    int j = high;

    while (i < j)
    {
        while(p >= arr[i]){
            i++;
        }

        while(p < arr[j]){
            j--;
        }

        if(i<j){
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    int t = arr[low];
    arr[low] = arr[j];
    arr[j] = t;

    return j;
    
}


void quickSort(int arr[], int low, int high){
    if (low < high)
    {
        int pivot = partition(arr,low,high);

        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot + 1,high);
    }
    
}
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;

    int arr[n];
    cout<<"Enter the "<<n<<" elements: "<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    quickSort(arr,0,n-1);

    cout<<"Sorted array: ";
    for(int i = 0; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}