#include <stdio.h>
#include <string.h>

#define MAX 1000

int longestValidParentheses(char *s) {
    int stack[MAX];
    int top = -1;
    int maxLen = 0;

    stack[++top] = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            // push index of '('
            stack[++top] = i;
        } else { // s[i] == ')'
            top--; // pop
            if (top == -1) {
                // stack empty, push current index as base
                stack[++top] = i;
            } else {
                // length = current_index - index_of_last_unmatched
                int len = i - stack[top];
                if (len > maxLen)
                    maxLen = len;
            }
        }
    }

    return maxLen;
}

int main() {
    char s[MAX];
    printf("Enter string containing only '(' and ')': ");
    scanf("%s", s);

    int result = longestValidParentheses(s);
    printf("Length of longest valid parentheses substring: %d\n", result);

    return 0;
}
