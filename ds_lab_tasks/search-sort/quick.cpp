#include <iostream>
using namespace std;


int partition(int arr[],int low,int high){
    int p = arr[low];
    int i = low + 1;
    int j = high;

    while(i < j){
        while(arr[i] <= p){
            i++;
        }

        while(arr[j] > p){
            j--;
        }

        if(i < j){
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
void quickSort(int arr[], int low, int high) {

    while(low < high){
        int pivot = partition(arr,low,high);

        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
    
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
