#include <iostream>
#include <cstring>  
using namespace std;

#define MAX 100   
class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(char ch) {
        if (top == MAX - 1) {
            cout << "Stack Overflow!" << endl;
        } else {
            arr[++top] = ch;
        }
    }

    char pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        } else {
            return arr[top--];
        }
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    char str[MAX];
    Stack s;

    cout << "Enter a string: ";
    cin.getline(str, MAX);

    // Push all characters of string onto stack
    for (int i = 0; str[i] != '\0'; i++) {
        s.push(str[i]);
    }

    // Pop characters to reverse string
    cout << "Reversed string: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;

    return 0;
}
