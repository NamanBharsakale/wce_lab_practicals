#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    public:
    Node(int data){
        val = data;
        right = NULL;
        left = NULL;
    }
};

Node * duplicateTree(Node* root){
    if(!root) return NULL;

    Node* temp = new Node(root->val);
    temp -> left = duplicateTree(root->left);
    temp -> right = duplicateTree(root ->right);


    return temp;

}

void inorder(Node* root){
    if(!root) return;

    inorder(root->left);
    cout<<" "<<root->val;
    inorder(root->right);

}
int main(){
    Node* root1;
    root1 = new Node(10);
    root1 -> left = new Node(20);
    root1 -> left -> left = new Node(21);
    root1 -> right =new Node(30);
    root1 -> right -> left =new Node(22);

    Node* root2 = duplicateTree(root1);
    cout<<"Inorder of root1: ";
    inorder(root1);
    cout<<"Inorder of root2: ";
    inorder(root2);

    return 0;

}