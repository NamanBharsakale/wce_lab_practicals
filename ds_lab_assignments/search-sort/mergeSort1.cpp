#include <iostream>
using namespace std;

void merge(int a[], int low,int mid, int high){
    int n1 = mid - low  + 1;
    int n2 = high - mid;

    int left[n1],right[n2];

    for(int i = 0; i < n1; i++){
        left[i] = a[low + i]
    }

    for(int j = 0; j < n2; j++){
        right[j] = a[mid + j + 1]
    }

    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            a[k] = left[i];
            i++;
        }

        if(right[j] < left[i]){
            a[k] = right[j];
            j++;
        }

        k++;
    }

    while(i < n1){
        a[k] = left[i];
        i++;
        k++;
    }

    while(j < n2){
        a[k] = right[j];
        j++;
        k++;
    }

}

void mergeSort(int a[],int low,int high){

    while(low < high){
        int mid = (high + low)/2;

        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);

        merge(a,low,mid,high);

    }


}
int main(){
    int n;
    cout<<"How many number you want to store: ";
    cin>>n;

    int a[n];
    cout<<"Enter "<<n<<" elements: ";
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    mergeSort(a,0,n - 1);
    cout<<"Sorted Array: ";
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}