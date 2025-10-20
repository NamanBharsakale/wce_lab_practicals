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
        left = NULL;
        right = NULL;
    }
};

Node* insert_bst(Node* root,int item){
    if(!root){
        return new Node(item);
    }
    
    if(root -> val > item){
        root -> right = insert_bst(root->right,item);
    }
    else {
        root -> left = insert_bst(root -> left,item);
    }

    return root;
}

void inorder(Node* root){
    if(!root) return;

    inorder(root->left);
    cout<<" "<<root->val;
    inorder(root->right);

}


int main(){
    Node* root = nullptr;

    cout
}