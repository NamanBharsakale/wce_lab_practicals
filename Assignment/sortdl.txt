#include <iostream>
using namespace std;

struct Nd {
    int dt;
    Nd* pr;
    Nd* nx;
};

Nd* hd = nullptr;

void inEd(int vl) {
    Nd* nn = new Nd();
    nn->dt = vl;
    nn->nx = nullptr;
    if (hd == nullptr) {
        nn->pr = nullptr;
        hd = nn;
        return;
    }
    Nd* tp = hd;
    while (tp->nx != nullptr) tp = tp->nx;
    tp->nx = nn;
    nn->pr = tp;
}

void dsp() {
    if (hd == nullptr) {
        cout << "List empty.\n";
        return;
    }
    Nd* tp = hd;
    cout << "List: ";
    while (tp != nullptr) {
        cout << tp->dt << " <-> ";
        tp = tp->nx;
    }
    cout << "NULL\n";
}

void sr() {
    if (hd == nullptr) return;
    int sw;
    Nd* tp;
    do {
        sw = 0;
        tp = hd;
        while (tp->nx != nullptr) {
            if (tp->dt > tp->nx->dt) {
                int tmp = tp->dt;
                tp->dt = tp->nx->dt;
                tp->nx->dt = tmp;
                sw = 1;
            }
            tp = tp->nx;
        }
    } while (sw);
}

int main() {
    int n, vl;
    cout << "Enter no. of nodes: ";
    cin >> n;
    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> vl;
        inEd(vl);
    }
    cout << "\nOriginal List:\n";
    dsp();
    sr();
    cout << "\nSorted List:\n";
    dsp();
    return 0;
}
