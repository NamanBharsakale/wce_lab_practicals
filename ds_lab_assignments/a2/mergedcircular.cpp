#include <iostream>
using namespace std;

struct Nd {
    int dt;
    Nd* nx;
};

void inEd(Nd*& hd, int vl) {
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

void dsp(Nd* hd) {
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

Nd* mgLst(Nd* h1, Nd* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    Nd* t1 = h1;
    while (t1->nx != h1) t1 = t1->nx;
    t1->nx = nullptr;

    Nd* t2 = h2;
    while (t2->nx != h2) t2 = t2->nx;
    t2->nx = nullptr;

    Nd* nh = nullptr;
    Nd* nt = nullptr;

    while (h1 && h2) {
        Nd* mn;
        if (h1->dt <= h2->dt) {
            mn = h1;
            h1 = h1->nx;
        } else {
            mn = h2;
            h2 = h2->nx;
        }

        if (!nh) {
            nh = mn;
            nt = mn;
        } else {
            nt->nx = mn;
            nt = mn;
        }
    }

    if (h1) nt->nx = h1;
    if (h2) nt->nx = h2;

    Nd* tp = nh;
    while (tp->nx != nullptr) tp = tp->nx;
    tp->nx = nh;

    return nh;
}

int main() {
    Nd* h1 = nullptr;
    Nd* h2 = nullptr;

    int n1, n2, vl;

    cout << "Enter no. of nodes in 1st list: ";
    cin >> n1;
    cout << "Enter sorted values:\n";
    for (int i = 0; i < n1; i++) {
        cin >> vl;
        inEd(h1, vl);
    }

    cout << "Enter no. of nodes in 2nd list: ";
    cin >> n2;
    cout << "Enter sorted values:\n";
    for (int i = 0; i < n2; i++) {
        cin >> vl;
        inEd(h2, vl);
    }

    cout << "\n1st Circular List:\n";
    dsp(h1);

    cout << "\n2nd Circular List:\n";
    dsp(h2);

    Nd* mh = mgLst(h1, h2);

    cout << "\nMerged Sorted Circular List:\n";
    dsp(mh);

    return 0;
}
