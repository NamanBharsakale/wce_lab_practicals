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

int CountNode(Node* root){
    if(!root){
        return 0;
    }

    return (1 + CountNode(root->left) + CountNode(root->right));
}

int main(){
    Node * root;
    root = BinaryTree();

    cout<<"Preorder COunt of Nodes: "<<CountNode(root);
   
    return 0;
}