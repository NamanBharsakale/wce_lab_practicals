#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int uc = 0; // unique count

    for (int i = 0; i < n; i++) {
        bool uq = true; // unique flag
        for (int j = 0; j < n; j++) {
            if (i != j && a[i] == a[j]) {
                uq = false;
                break;
            }
        }
        if (uq) uc++;
    }

    cout << "Unique elements count = " << uc << endl;
    return 0;
}
