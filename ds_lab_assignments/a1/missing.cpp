#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int a[n], sm = 0;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sm += a[i];
    }

    int ts = (n + 1) * (n + 2) / 2; 
    int ms = ts - sm; 

    cout << "Missing element = " << ms << endl;
    return 0;
}
