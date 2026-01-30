#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* right;
    Node* left;
    public:
    Node(int data){
        val = data;
        right = NULL;
        left = NULL;
    }
};

Node * BinaryTree(){
    int x;
    cin>>x;

    if(x == -1) return NULL;
    Node* temp = new Node(x);
    cout<<"Enter the left child of "<<x<<": ";
    temp -> left = BinaryTree();
    cout<<"Enter the right child of "<<x<<": ";
    temp -> right = BinaryTree();

    return temp;
}

void preorder(Node* root){
    if(!root) return;
   
    cout<<" "<<root->val;
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(Node* root){
    if(!root) return;

    inorder(root -> left);
    cout<<" "<<root->val;
    inorder(root -> right);
}

void postorder(Node* root){
    if(!root) return;

    postorder(root -> left);
    postorder(root -> right);
    cout<<" "<<root->val;
}

int main(){
    Node * root;
    root = BinaryTree();

    cout<<"Preorder Traversal: ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder Traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"Postorder Traversal: ";
    postorder(root);
    return 0;
}