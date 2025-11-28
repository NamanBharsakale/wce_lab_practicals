#include <iostream>
using namespace std;

int main() {
    int a, b, lcm, gcd, x, y;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    x = a; y = b;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    gcd = a;
    lcm = (x * y) / gcd;

    cout << "LCM = " << lcm;
    return 0;
}
