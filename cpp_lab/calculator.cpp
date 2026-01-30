#include <iostream>
using namespace std;

int main() {
    char op;
    double a, b;
    cout << "Enter expression (a + b): ";
    cin >> a >> op >> b;

    switch (op) {
        case '+': cout << "Result = " << a + b; break;
        case '-': cout << "Result = " << a - b; break;
        case '*': cout << "Result = " << a * b; break;
        case '/': 
            if (b != 0) cout << "Result = " << a / b;
            else cout << "Division by zero not allowed";
            break;
        default: cout << "Invalid operator";
    }

    return 0;
}
