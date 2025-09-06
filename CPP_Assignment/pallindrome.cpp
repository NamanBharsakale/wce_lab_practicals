#include <iostream>
using namespace std;

int main() {
    int n, rev = 0, temp;
    cout << "Enter number: ";
    cin >> n;
    temp = n;

    while (temp > 0) {
        rev = rev * 10 + (temp % 10);
        temp /= 10;
    }

    if (rev == n)
        cout << n << " is Palindrome";
    else
        cout << n << " is NOT Palindrome";

    return 0;
}
