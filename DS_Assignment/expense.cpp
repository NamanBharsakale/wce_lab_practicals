#include <iostream>
using namespace std;

struct Item {
    char name[50];
    float price;
    int qty;
};

int main() {
    int C, N;
    cin >> C;   
    cin >> N;   

    Item arr[100];
    float total = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i].name >> arr[i].price >> arr[i].qty;
        total += arr[i].price * arr[i].qty;
    }

    float perPerson = total / C;

    int t1 = (int)(total * 100 + 0.5);
    int p1 = (int)(perPerson * 100 + 0.5);

    cout << t1 / 100 << "." << (t1 % 100 < 10 ? "0" : "") << t1 % 100 << endl;
    cout << p1 / 100 << "." << (p1 % 100 < 10 ? "0" : "") << p1 % 100 << endl;

    for (int i = 0; i < N; i++) {
        float itemTotal = arr[i].price * arr[i].qty;
        int it = (int)(itemTotal * 100 + 0.5);
        cout << arr[i].name << " " << it / 100 << "." << (it % 100 < 10 ? "0" : "") << it % 100 << endl;
    }

    return 0;
}
