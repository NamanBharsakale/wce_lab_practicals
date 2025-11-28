#include <iostream>
#include <cstdlib>   

using namespace std;

int main() {
    int N;

    cout << "Enter the size of the array: ";
    cin >> N;

    int* arr = (int*)malloc(N * sizeof(int));

    if (arr == NULL) {
        cout << "Memory allocation failed!" << endl;
        return 1;
    }

    cout << "Enter " << N << " elements: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }

    cout << "Sum of even numbers = " << sum << endl;

    free(arr);

    return 0;
}
