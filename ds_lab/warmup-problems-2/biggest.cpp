#include <iostream>
using namespace std;

int findMax(int arr[], int n) {
    if (n == 1)
        return arr[0];

    int temp = findMax(arr, n - 1);

    if (arr[n - 1] > temp)
        return arr[n - 1];
    else
        return temp;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int largest = findMax(arr, n);

    cout << "The biggest number in the array is: " << largest << endl;

    return 0;
}
