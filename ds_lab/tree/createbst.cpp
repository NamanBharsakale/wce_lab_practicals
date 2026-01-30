#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *left, *right;

    Node(int data) {
        val = data;
        left = right = nullptr;
    }
};

// Function to insert a value in BST
Node* insert_Bst(Node* root, int data) {
    if (!root) {
        return new Node(data);
    }
    if (data <= root->val) {
        root->left = insert_Bst(root->left, data);
    } else {
        root->right = insert_Bst(root->right, data);
    }
    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int minBst(Node* root){
    if(!root){
        cout<<"BST is empty..";
        return -1;
    }
    Node* current;
    current = root -> left;
    while(current -> left != nullptr){
        current = current -> left;
    }

    return current -> val;

}
int main() {
    Node* root = nullptr;
    int n, value;

    cout << "How many nodes do you want to insert in BST? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        root = insert_Bst(root, value);
    }

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;
    cout<<"Minimum: "<<minBst(root);
    return 0;
}
