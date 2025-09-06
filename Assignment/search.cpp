#include <iostream>
using namespace std;

struct Nd {
    int dt;
    Nd* nx;
};

void inEd(Nd*& hd, int vl) {
    Nd* nn = new Nd();
    nn->dt = vl;
    nn->nx = nullptr;

    if (hd == nullptr) {
        hd = nn;
    } else {
        Nd* tp = hd;
        while (tp->nx != nullptr) {
            tp = tp->nx;
        }
        tp->nx = nn;
    }
}

bool srRc(Nd* hd, int vl) {
    if (hd == nullptr) return false;       
    if (hd->dt == vl) return true;         
    return srRc(hd->nx, vl);               
}

void dsp(Nd* hd) {
    if (hd == nullptr) {
        cout << "List empty.\n";
        return;
    }
    Nd* tp = hd;
    cout << "List: ";
    while (tp != nullptr) {
        cout << tp->dt << " -> ";
        tp = tp->nx;
    }
    cout << "NULL\n";
}

int main() {
    Nd* hd = nullptr;
    int n, vl, se;

    cout << "Enter no. of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> vl;
        inEd(hd, vl);
    }

    cout << "\nLinked List:\n";
    dsp(hd);

    cout << "Enter element to search: ";
    cin >> se;

    if (srRc(hd, se))
        cout << se << " found in list.\n";
    else
        cout << se << " not found in list.\n";

    return 0;
}
