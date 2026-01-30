#include <iostream>
#include <cstdlib>   // for malloc() and free()

using namespace std;

int main() {
    // Allocate memory for int, char and float
    int* N = (int*)malloc(sizeof(int));
    char* C = (char*)malloc(sizeof(char));
    float* F = (float*)malloc(sizeof(float));

    // Check if memory allocation was successful
    if (N == NULL || C == NULL || F == NULL) {
        cout << "Memory allocation failed!" << endl;
        return 1; // exit with error
    }

    // Input values
    cout << "Enter an integer: ";
    cin >> *N;

    cout << "Enter a character: ";
    cin >> *C;

    cout << "Enter a float: ";
    cin >> *F;

    // Display values
    cout << "\nYou entered:" << endl;
    cout << "Integer: " << *N << endl;
    cout << "Character: " << *C << endl;
    cout << "Float: " << *F << endl;

    // Free allocated memory
    free(N);
    free(C);
    free(F);

    return 0;
}
