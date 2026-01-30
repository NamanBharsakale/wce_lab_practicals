#include <iostream>
using namespace std;

#define MAX 50   // maximum nodes allowed in stack

// Node of the binary tree
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int data) {
        val = data;
        left = right = NULL;
    }
};

// Stack implemented using array
class Stack {
public:
    Node* arr[MAX];
    int top;

    Stack() {
        top = -1;
    }

    void push(Node* node) {
        if (top == MAX - 1) {
            cout << "Stack overflow!\n";
            return;
        }
        arr[++top] = node;
    }

    Node* pop() {
        if (top == -1) {
            return NULL;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Count nodes in binary tree (Preorder traversal)
int CountNode(Node* root) {
    if (root == NULL)
        return 0;

    Stack s;
    s.push(root);
    int count = 0;

    while (!s.isEmpty()) {
        Node* node = s.pop();
        count++;

        // Push right first so left is processed first (preorder)
        if (node->right)
            s.push(node->right);
        if (node->left)
            s.push(node->left);
    }

    return count;
}

// Helper: create a simple binary tree
Node* BinaryTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    return root;
}

int main() {
    Node* root = BinaryTree();

    cout << "Preorder count of nodes: " << CountNode(root) << endl;

    return 0;
}
