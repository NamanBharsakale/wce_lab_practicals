#include <iostream>
using namespace std;

int main() {
    int n; 
    cout << "Enter number of cars: ";
    cin >> n; 

    int cars[1000];
    cout << "Enter the car number plates: ";
    for (int i = 0; i < n; i++) {
        cin >> cars[i];
    }

    int day;
    cout << "Enter the day of the month (1-31): ";
    cin >> day;

    int fine = 0;

    for (int i = 0; i < n; i++) {
        int car = cars[i];

        if ((day % 2 == 0 && car % 2 != 0) || (day % 2 != 0 && car % 2 == 0)) {
            fine += 250;
        }
    }

    cout << "Total fine = " << fine << endl;

    return 0;
}
