#include <iostream>
#include <cmath>
using namespace std;

int main() {
    for (int n = 1; n <= 1000; n++) {
        int sum = 0, temp = n, digits = 0;
        while (temp > 0) {
            digits++;
            temp /= 10;
        }
        temp = n;
        while (temp > 0) {
            int d = temp % 10;
            sum += d ** digits;
            temp /= 10;
        }
        if (sum == n) cout << n << " ";
    }

    return 0;
}

//
// I am working on the user authentication system and also gives permissions 
// depends on different user roles


// And improving the design and layout of the website's user interface based on latest suggestion
