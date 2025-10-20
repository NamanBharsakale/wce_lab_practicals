#include <iostream>
using namespace std;

struct Nd {
    int dt;
    Nd* nx;
};

Nd* hd = nullptr;

void inEd(int vl) {
    Nd* nn = new Nd();
    nn->dt = vl;
    if (hd == nullptr) {
        hd = nn;
        nn->nx = hd;
    } else {
        Nd* tp = hd;
        while (tp->nx != hd) {
            tp = tp->nx;
        }
        tp->nx = nn;
        nn->nx = hd;
    }
}

void dlEv() {
    if (hd == nullptr || hd->nx == hd) {
        return;
    }

    Nd* tp = hd;
    Nd* pr = nullptr;
    int ps = 1;

    do {
        if (ps % 2 == 0) {  
            pr->nx = tp->nx;
            Nd* dl = tp;
            tp = tp->nx;
            delete dl;
        } else {
            pr = tp;
            tp = tp->nx;
        }
        ps++;
    } while (tp != hd);

    if (hd != nullptr && ps > 2 && (2 % 2 == 0)) {
        hd = pr->nx;
    }
}

void dsp() {
    if (hd == nullptr) {
        cout << "List empty.\n";
        return;
    }
    Nd* tp = hd;
    cout << "Circular List: ";
    do {
        cout << tp->dt << " -> ";
        tp = tp->nx;
    } while (tp != hd);
    cout << "(back to head)\n";
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

    dlEv();

    cout << "\nAfter deleting even pos nodes:\n";
    dsp();

    return 0;
}
