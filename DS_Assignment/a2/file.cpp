#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char file1[50], file2[50], file3[50];
    cout << "Enter first input file name: ";
    cin >> file1;
    cout << "Enter second input file name: ";
    cin >> file2;
    cout << "Enter output file name: ";
    cin >> file3;

    ifstream fin1(file1);
    ifstream fin2(file2);
    ofstream fout(file3);

    if (!fin1.is_open() || !fin2.is_open() || !fout.is_open()) {
        cout << "Error opening file(s)!" << endl;
        return 1;
    }

    char line1[256], line2[256];  
    bool turn = true;

    while (true) {
        if (turn) {
            if (fin1.getline(line1, 256)) {
                fout << line1 << "\n";
            } else if (fin2.getline(line2, 256)) {
                fout << line2 << "\n";
            } else {
                break; 
            }
        } else {
            if (fin2.getline(line2, 256)) {
                fout << line2 << "\n";
            } else if (fin1.getline(line1, 256)) {
                fout << line1 << "\n";
            } else {
                break;
            }
        }
        turn = !turn; 
    }

    cout << "Files merged successfully into " << file3 << endl;

    fin1.close();
    fin2.close();
    fout.close();

    return 0;
}
