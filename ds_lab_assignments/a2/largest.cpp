#include <iostream>
#include <cstdlib>   
using namespace std;

int main() {
    int N;

    cout << "Enter the size of the array: ";
    cin >> N;

    int* A = (int*)calloc(N, sizeof(int));

    if (A == NULL) {
        cout << "Memory allocation failed!" << endl;
        return 1;
    }

    cout << "Enter " << N << " elements: ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int largest = A[0];
    for (int i = 1; i < N; i++) {
        if (A[i] > largest) {
            largest = A[i];
        }
    }

    cout << "The largest element is: " << largest << endl;

    free(A);

    return 0;
}
