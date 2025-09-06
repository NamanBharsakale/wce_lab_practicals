#include <iostream>
using namespace std;

struct Nd {
    int dt;
    Nd* pr;
    Nd* nx;
};

Nd* hd = nullptr;

void inBg(int vl) {
    Nd* nn = new Nd();
    nn->dt = vl;
    nn->pr = nullptr;
    nn->nx = hd;
    if (hd != nullptr) hd->pr = nn;
    hd = nn;
}

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

void inPs(int vl, int ps) {
    Nd* nn = new Nd();
    nn->dt = vl;
    if (ps == 1) {
        nn->pr = nullptr;
        nn->nx = hd;
        if (hd != nullptr) hd->pr = nn;
        hd = nn;
        return;
    }
    Nd* tp = hd;
    for (int i = 1; tp != nullptr && i < ps - 1; i++) tp = tp->nx;
    if (tp == nullptr) return;
    nn->nx = tp->nx;
    if (tp->nx != nullptr) tp->nx->pr = nn;
    tp->nx = nn;
    nn->pr = tp;
}

void dlBg() {
    if (hd == nullptr) return;
    Nd* tp = hd;
    hd = hd->nx;
    if (hd != nullptr) hd->pr = nullptr;
    delete tp;
}

void dlEd() {
    if (hd == nullptr) return;
    if (hd->nx == nullptr) {
        delete hd;
        hd = nullptr;
        return;
    }
    Nd* tp = hd;
    while (tp->nx != nullptr) tp = tp->nx;
    tp->pr->nx = nullptr;
    delete tp;
}

void dlPs(int ps) {
    if (hd == nullptr) return;
    if (ps == 1) {
        Nd* tp = hd;
        hd = hd->nx;
        if (hd != nullptr) hd->pr = nullptr;
        delete tp;
        return;
    }
    Nd* tp = hd;
    for (int i = 1; tp != nullptr && i < ps; i++) tp = tp->nx;
    if (tp == nullptr) return;
    if (tp->pr != nullptr) tp->pr->nx = tp->nx;
    if (tp->nx != nullptr) tp->nx->pr = tp->pr;
    delete tp;
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

int main() {
    int ch, vl, ps;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter val: "; cin >> vl; inBg(vl); break;
            case 2: cout << "Enter val: "; cin >> vl; inEd(vl); break;
            case 3: cout << "Enter val & pos: "; cin >> vl >> ps; inPs(vl, ps); break;
            case 4: dlBg(); break;
            case 5: dlEd(); break;
            case 6: cout << "Enter pos: "; cin >> ps; dlPs(ps); break;
            case 7: dsp(); break;
            case 0: cout << "Exit...\n"; break;
            default: cout << "Invalid!\n";
        }
    } while (ch != 0);
    return 0;
}
