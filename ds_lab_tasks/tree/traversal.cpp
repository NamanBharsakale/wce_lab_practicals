#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node *right,*left;
    public:
    Node(int data){
        right = NULL;
        left = NULL;
        val = data;
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
    if(root == NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root ->left);
    postorder(root -> right);
    cout<<root->val<<" ";
}
int main(){
    cout<<"Enter the root of Binary tree: ";
    Node *root;
    root = BinaryTree();

    cout<<"Preorder: ";
    preorder(root);
    cout<<"Inorder: ";
    inorder(root);
    cout<<"Postorder: ";
    postorder(root);

    return 0;
}