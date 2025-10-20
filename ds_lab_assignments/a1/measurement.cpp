#include <iostream>
using namespace std;

struct Measurement {
    int inch;
    float feet;
};

int main() {
    Measurement m1, m2, sum;

    cin >> m1.inch >> m1.feet;
    cin >> m2.inch >> m2.feet;

    sum.inch = m1.inch + m2.inch;
    sum.feet = m1.feet + m2.feet;

    while (sum.feet >= 12.0) {
        sum.inch += 1;
        sum.feet -= 12.0;
    }

    int f = (int)(sum.feet * 10 + 0.5);

    cout << sum.inch << " " << f / 10 << "." << f % 10 << endl;

    return 0;
}
