#include <iostream>
#include <cstdlib>   // for malloc() and free()

using namespace std;

void swapArrays(int* arr1, int* arr2, int n) {
    for (int i = 0; i < n; i++) {
        int temp = *(arr1 + i);
        *(arr1 + i) = *(arr2 + i);
        *(arr2 + i) = temp;
    }
}

int main() {
    int n;

    cout << "Enter the size of the arrays: ";
    cin >> n;

    // Allocate memory for two arrays
    int* A = (int*)malloc(n * sizeof(int));
    int* B = (int*)malloc(n * sizeof(int));

    if (A == NULL || B == NULL) {
        cout << "Memory allocation failed!" << endl;
        return 1;
    }

    // Input values for first array
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Input values for second array
    cout << "Enter elements of second array: ";
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    // Swap arrays using pointers
    swapArrays(A, B, n);

    // Display results
    cout << "\nAfter swapping:" << endl;
    cout << "First array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "Second array: ";
    for (int i = 0; i < n; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    // Free memory
    free(A);
    free(B);

    return 0;
}
