#include <iostream>
using namespace std;

struct student {
    char name[50];
    int id;
};

student* solution(int N) 
{
    static student arr[100]; 
    for (int i = 0; i < N; i++) {
        cout << "Enter name for student " << i + 1 << ": ";
        cin >> arr[i].name;
        cout << "Enter id for student " << i + 1 << ": ";
        cin >> arr[i].id;
    }

    for (int i = 0; i < N - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < N; j++) {
            if (arr[j].id < arr[minIdx].id) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            student temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }

    return arr;
}

int main() {
    int N;
    cout << "Enter number of students: ";
    cin >> N;

    student* sortedArr = solution(N);

    cout << "\nSorted students (by id):\n";
    for (int i = 0; i < N; i++) {
        cout << "ID: " << sortedArr[i].id << "  Name: " << sortedArr[i].name << endl;
    }

    return 0;
}
