#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_WORDS = 1000;   
const int MAX_LEN   = 50;     

int main() {
    char filename[50];
    cout << "Enter file name: ";
    cin >> filename;

    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    char words[MAX_WORDS][MAX_LEN]; 
    int count[MAX_WORDS] = {0};    
    int wordIndex = 0;

    char word[MAX_LEN];

    while (fin >> word) {
        for (int i = 0; word[i]; i++) {
            if (word[i] >= 'A' && word[i] <= 'Z')
                word[i] = word[i] + 32; 
        }

        bool found = false;
        for (int i = 0; i < wordIndex; i++) {
            if (strcmp(words[i], word) == 0) {
                count[i]++;
                found = true;
                break;
            }
        }

        if (!found && wordIndex < MAX_WORDS) {
            strcpy(words[wordIndex], word);
            count[wordIndex] = 1;
            wordIndex++;
        }
    }

    fin.close();

    cout << "\nWord occurrences:\n";
    for (int i = 0; i < wordIndex; i++) {
        cout << words[i] << " : " << count[i] << endl;
    }

    return 0;
}
