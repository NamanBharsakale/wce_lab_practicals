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

Node* duplicateTree(Node* root){
    if(!root) 
    {
        return NULL;
    }
    
    Node* ptr =new Node(root->val);
    if(root->left){
        ptr -> left = duplicateTree(root->left);
    }

    if(root -> right){
        ptr -> right = duplicateTree(root->right);
    }

    return ptr;

}

void preorder(Node* root){
    if(!root) return;

    cout<<" "<<root ->val;
    preorder(root->left);
    preorder(root->right);
}
int main(){
    Node* root1;

    root1 = new Node(10);
    root1 -> left = new Node(20);
    root1 -> left -> left = new Node(21);
    root1 -> right =new Node(30);
    root1 -> right -> left =new Node(22);

    cout<<"Preorder of original tree: ";
    preorder(root1);

    cout<<endl;
    cout<<"Preorder of duplicate tree: ";
    preorder(duplicateTree(root1));

    return 0;
}