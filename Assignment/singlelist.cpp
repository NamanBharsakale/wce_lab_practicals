#include <iostream>
using namespace std;

struct Nd {
    int dt;
    Nd* nx;
};

Nd* hd = nullptr;  

void inBg(int vl) {
    Nd* nn = new Nd();
    nn->dt = vl;
    nn->nx = hd;
    hd = nn;
    cout << "Inserted " << vl << " at beginning.\n";
}

void inEd(int vl) {
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
    cout << "Inserted " << vl << " at end.\n";
}

void inPs(int vl, int ps) {
    Nd* nn = new Nd();
    nn->dt = vl;

    if (ps == 1) {
        nn->nx = hd;
        hd = nn;
        cout << "Inserted " << vl << " at pos " << ps << ".\n";
        return;
    }

    Nd* tp = hd;
    for (int i = 1; tp != nullptr && i < ps - 1; i++) {
        tp = tp->nx;
    }

    if (tp == nullptr) {
        cout << "Pos out of range.\n";
        delete nn;
        return;
    }

    nn->nx = tp->nx;
    tp->nx = nn;
    cout << "Inserted " << vl << " at pos " << ps << ".\n";
}

void dlBg() {
    if (hd == nullptr) {
        cout << "List empty.\n";
        return;
    }
    Nd* tp = hd;
    hd = hd->nx;
    cout << "Deleted " << tp->dt << " from beginning.\n";
    delete tp;
}

void dlEd() {
    if (hd == nullptr) {
        cout << "List empty.\n";
        return;
    }
    if (hd->nx == nullptr) {
        cout << "Deleted " << hd->dt << " from end.\n";
        delete hd;
        hd = nullptr;
        return;
    }
    Nd* tp = hd;
    while (tp->nx->nx != nullptr) {
        tp = tp->nx;
    }
    cout << "Deleted " << tp->nx->dt << " from end.\n";
    delete tp->nx;
    tp->nx = nullptr;
}

void dlPs(int ps) {
    if (hd == nullptr) {
        cout << "List empty.\n";
        return;
    }
    if (ps == 1) {
        Nd* tp = hd;
        hd = hd->nx;
        cout << "Deleted " << tp->dt << " from pos " << ps << ".\n";
        delete tp;
        return;
    }

    Nd* tp = hd;
    for (int i = 1; tp != nullptr && i < ps - 1; i++) {
        tp = tp->nx;
    }

    if (tp == nullptr || tp->nx == nullptr) {
        cout << "Pos out of range.\n";
        return;
    }

    Nd* dl = tp->nx;
    tp->nx = tp->nx->nx;
    cout << "Deleted " << dl->dt << " from pos " << ps << ".\n";
    delete dl;
}

void dsp() {
    if (hd == nullptr) {
        cout << "List empty.\n";
        return;
    }
    Nd* tp = hd;
    cout << "Linked List: ";
    while (tp != nullptr) {
        cout << tp->dt << " -> ";
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
            case 1:
                cout << "Enter val: ";
                cin >> vl;
                inBg(vl);
                break;
            case 2:
                cout << "Enter val: ";
                cin >> vl;
                inEd(vl);
                break;
            case 3:
                cout << "Enter val & pos: ";
                cin >> vl >> ps;
                inPs(vl, ps);
                break;
            case 4:
                dlBg();
                break;
            case 5:
                dlEd();
                break;
            case 6:
                cout << "Enter pos: ";
                cin >> ps;
                dlPs(ps);
                break;
            case 7:
                dsp();
                break;
            case 0:
                cout << "Exit...\n";
                break;
            default:
                cout << "Invalid!\n";
        }
    } while (ch != 0);

    return 0;
}
