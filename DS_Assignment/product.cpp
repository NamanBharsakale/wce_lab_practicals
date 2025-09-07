#include <iostream>
using namespace std;

struct Product {
    int id;
    char name[50];
    int qty;
    float price;
};

int main() {
    Product p;

    cout << "Enter product id: ";
    cin >> p.id;

    cout << "Enter product name: ";
    cin >> p.name;

    cout << "Enter product quantity: ";
    cin >> p.qty;

    cout << "Enter product price: ";
    cin >> p.price;

    float total = p.qty * p.price;

    cout << "\n--- Product Details ---\n";
    cout << "ID       : " << p.id << endl;
    cout << "Name     : " << p.name << endl;
    cout << "Quantity : " << p.qty << endl;
    cout << "Price    : " << p.price << endl;
    cout << "Total    : " << total << endl;

    return 0;
}
