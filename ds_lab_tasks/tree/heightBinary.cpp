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
        left = NULL;
        right = NULL;
    }
};

Node* BinaryTree(){
    int x;
    cin>>x;

    if(x == -1) return NULL;

    Node* temp = new Node(x);
    cout<<"Enter the left child of "<<x<<" : ";
    temp -> left = BinaryTree();
    cout<<"Enter the right child of "<<x<<" : ";
    temp -> right = BinaryTree();

    return temp;
}


void inorder(Node* root){
    if(!root) return;

    inorder(root -> left);
    cout<<" "<<root -> val;
    inorder(root -> right);

}

int heightBt(Node* root){
    if(!root) return 0;

    int left = heightBt(root -> left);
    int right = heightBt(root -> right);

    int max = left > right ? left : right;
    return (1 + max );
}
int main(){
    Node* root = nullptr;

    cout<<"ENter the root node: ";
    root = BinaryTree();

    cout<<"Inorder Traversal : ";
    inorder(root);

    cout<<"Height of tree is: "<<heightBt(root);
    return 0;
}