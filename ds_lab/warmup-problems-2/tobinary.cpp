#include <iostream>
using namespace std;

void toBinary(int N) {
    if (N == 0)
        return;

    toBinary(N / 2);      
    cout << (N % 2);      
}

int main() {
    int N;
    cout << "Enter an integer: ";
    cin >> N;

    if (N == 0) {
        cout << "Binary: 0" << endl;
    } else {
        cout << "Binary: ";
        toBinary(N);
        cout << endl;
    }

    return 0;
}
