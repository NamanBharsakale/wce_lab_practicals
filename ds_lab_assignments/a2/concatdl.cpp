#include <iostream>
using namespace std;

struct Nd {
    int dt;
    Nd* pr;
    Nd* nx;
};

Nd* hd1 = nullptr;
Nd* hd2 = nullptr;

void inEd(Nd*& hd, int vl) {
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

void dsp(Nd* hd) {
    if (hd == nullptr) {
        cout << "List empty.\n";
        return;
    }
    Nd* tp = hd;
    while (tp != nullptr) {
        cout << tp->dt << " <-> ";
        tp = tp->nx;
    }
    cout << "NULL\n";
}

Nd* ct(Nd* h1, Nd* h2) {
    if (h1 == nullptr) return h2;
    if (h2 == nullptr) return h1;
    Nd* tp = h1;
    while (tp->nx != nullptr) tp = tp->nx;
    tp->nx = h2;
    h2->pr = tp;
    return h1;
}

int main() {
    int n1, n2, vl;
    cout << "Enter no. of nodes in 1st list: ";
    cin >> n1;
    cout << "Enter values:\n";
    for (int i = 0; i < n1; i++) {
        cin >> vl;
        inEd(hd1, vl);
    }
    cout << "Enter no. of nodes in 2nd list: ";
    cin >> n2;
    cout << "Enter values:\n";
    for (int i = 0; i < n2; i++) {
        cin >> vl;
        inEd(hd2, vl);
    }
    cout << "\n1st List:\n";
    dsp(hd1);
    cout << "\n2nd List:\n";
    dsp(hd2);
    Nd* hd3 = ct(hd1, hd2);
    cout << "\nConcatenated List:\n";
    dsp(hd3);
    return 0;
}
