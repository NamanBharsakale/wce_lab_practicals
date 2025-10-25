#include <iostream>
using namespace std;

int main() {
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    // Linear Search
    int pos = -1;  // To store index if found
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            pos = i;  // Store index
            break;    // Stop searching after finding the element
        }
    }

    if (pos != -1)
        cout << "Element found at index " << pos << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
