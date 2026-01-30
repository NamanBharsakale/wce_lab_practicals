#include <iostream>
using namespace std;

int main() {
    int n, fact = 1;
    cout << "Enter number: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        fact *= i;
    }

    cout << "Factorial = " << fact;
    return 0;
}
