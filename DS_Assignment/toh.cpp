#include <iostream>
using namespace std;

void toh(int nd, char fr, char to, char ax) {
    if (nd == 1) {
        cout << "Move disk 1 from " << fr << " to " << to << endl;
        return;
    }
    toh(nd - 1, fr, ax, to);

    cout << "Move disk " << nd << " from " << fr << " to " << to << endl;

    toh(nd - 1, ax, to, fr);
}

int main() {
    int nd;
    cout << "Enter number of disks: ";
    cin >> nd;

    cout << "\nSteps to solve Tower of Hanoi with " << nd << " disks:\n";
    toh(nd, 'A', 'C', 'B');  

    return 0;
}
