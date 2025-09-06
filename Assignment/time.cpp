#include <iostream>
using namespace std;

struct Time {
    int h;
    int m;
    int s; 
};

Time findDiff(Time t1, Time t2) {
    Time diff;

    int sec1 = t1.h * 3600 + t1.m * 60 + t1.s;
    int sec2 = t2.h * 3600 + t2.m * 60 + t2.s;

    int d = sec1 - sec2;

    if (d < 0) d = -d;

    diff.h = d / 3600;
    d %= 3600;
    diff.m = d / 60;
    diff.s = d % 60;

    return diff;
}

int main() {
    Time t1, t2, diff;

    cout << "Enter first time (hh mm ss): ";
    cin >> t1.h >> t1.m >> t1.s;

    cout << "Enter second time (hh mm ss): ";
    cin >> t2.h >> t2.m >> t2.s;

    diff = findDiff(t1, t2);

    cout << "Difference = " 
         << diff.h << " hours, " 
         << diff.m << " minutes, " 
         << diff.s << " seconds." << endl;

    return 0;
}
