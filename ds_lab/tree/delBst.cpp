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
Node* insert_Bst(Node* root, int data) 
{
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


void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout<<root->val<< " ";
    inorder(root->right);
}


Node* deleteNode(Node* root, int target){
    if(!root) return NULL;

    if(root->val > target) 
    {
        root->left = deleteNode(root->left, target);
    }
    else if(root->val < target){
        root->right = deleteNode(root->right, target);
    }
    else{
        if(!root->left && !root->right)//no child
        {
            delete root;
            return NULL;
        }
        else if(!root->right)//only left exists
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(!root->left)//only right exists
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else{//both children exist
            Node* child = root->left;
            Node* parent = root;
            //rightmost node
            while(child->right != nullptr){
                parent = child;
                child = child->right;
            }

            if(root != parent){
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else{
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }
    return root;
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

    cout << "BST in-order: ";
    inorder(root);
    cout << endl;

    cout << "Enter value to delete: ";
    int delVal;
    cin >> delVal;
    root = deleteNode(root, delVal);

    cout << "BST in-order after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
