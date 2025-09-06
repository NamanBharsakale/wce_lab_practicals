#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, sum = 0, temp, digits = 0;
    cout << "Enter number: ";
    cin >> n;
    temp = n;

    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = n;
    while (temp > 0) {
        int d = temp % 10;
        sum += pow(d, digits);
        temp /= 10;
    }

    if (sum == n) cout << n << " is Armstrong";
    else cout << n << " is NOT Armstrong";

    return 0;
}
