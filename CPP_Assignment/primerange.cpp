#include <iostream>
using namespace std;

int main() {
    int low, high;
    cout << "Enter range: ";
    cin >> low >> high;

    for (int n = low; n <= high; n++) {
        int flag = 1;
        if (n <= 1) flag = 0;
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) cout << n << " ";
    }

    return 0;
}
