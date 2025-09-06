#include <iostream>
using namespace std;

int main() {
    int start, end;
    cout << "Enter range: ";
    cin >> start >> end;

    for (int n = start; n <= end; n++) {
        int sq = n * n, sum = 0, temp = sq;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == n)
            cout << n << " ";
    }

    return 0;
}
