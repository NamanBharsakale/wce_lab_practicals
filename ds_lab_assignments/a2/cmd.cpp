#include <iostream>
using namespace std;

int stToIn(char* st) {
    int su = 0, i = 0, sg = 1;

    if (st[0] == '-') {
        sg = -1;
        i = 1;
    }

    while (st[i] != '\0') {
        su = su * 10 + (st[i] - '0'); 
        i++;
    }
    return sg * su;
}

int main(int ac, char* av[]) {
    int su = 0;

    for (int i = 1; i < ac; i++) {
        su += stToIn(av[i]);
    }

    cout << "Sum = " << su << endl;
    return 0;
}
