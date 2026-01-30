#include <iostream>
using namespace std;


int A[100];
int idx = 0;


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


void inorder(Node* root){
    if(!root) return;

    inorder(root->left);
    A[idx++] = root->val;
    inorder(root->right);

}

bool isBst(Node* root){
    idx = 0;
    inorder(root);
    for(int i = 1 ;i<idx;i++){
        if(A[i] < A[i-1]) return false;
    }

    return true;

}

int main(){
    Node* root = new Node(34);
    
    root -> left = new Node(18);
    root -> left -> left = new Node(12);
    root -> left -> right = new Node(19);
    root -> right = new Node(60);
    root -> right -> left = new Node(44);
    root -> right -> right = new Node(66);


    if(isBst(root)){
        cout<<"Yes , it is";
    }
    else{
        cout<<"No..";
    }

    return 0;
}