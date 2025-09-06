#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int a = 0, b = 1, fib;
    if (n == 1) fib = 0;
    else if (n == 2) fib = 1;
    else {
        for (int i = 3; i <= n; i++) {
            fib = a + b;
            a = b;
            b = fib;
        }
    }

    cout << "Fibonacci(" << n << ") = " << fib;
    return 0;
}
