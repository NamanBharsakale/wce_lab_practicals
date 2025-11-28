#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000  // maximum input size

// Manual stack for indices
struct Stack {
    int arr[MAX];
    int top;
};

// stack helper functions
void init(Stack &s) {
    s.top = -1;
}

bool isEmpty(Stack &s) {
    return s.top == -1;
}

void push(Stack &s, int val) {
    if (s.top < MAX - 1) {
        s.arr[++s.top] = val;
    }
}

int pop(Stack &s) {
    if (!isEmpty(s)) {
        return s.arr[s.top--];
    }
    return -1; // underflow
}

int peek(Stack &s) {
    if (!isEmpty(s)) {
        return s.arr[s.top];
    }
    return -1;
}

// core function
int longestValidParentheses(const char *s) {
    int n = strlen(s);
    Stack st;
    init(st);

    int max_len = 0;
    push(st, -1); // base index

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            push(st, i);
        } else { // s[i] == ')'
            pop(st);
            if (isEmpty(st)) {
                // no base left, push current index as base
                push(st, i);
            } else {
                // valid substring length = i - top
                int len = i - peek(st);
                if (len > max_len)
                    max_len = len;
            }
        }
    }
    return max_len;
}

int main() {
    char s[MAX];
    cout << "Enter the parentheses string: ";
    cin >> s;

    int result = longestValidParentheses(s);
    cout << "Length of longest valid parentheses substring: " << result << endl;

    return 0;
}
