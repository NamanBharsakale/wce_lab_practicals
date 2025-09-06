#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int a = 0, b = 1, sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) sum += b;
        int temp = b;
        b = a + b;
        a = temp;
    }

    cout << "Sum = " << sum;
    return 0;
}
