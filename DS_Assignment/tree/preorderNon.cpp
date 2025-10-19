#include <iostream>
#include <stack>
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
    cout<<"Enter the left child of "<<x<<" :";
    temp -> left = BinaryTree();
    cout<<"Enter the right child of "<<x<<" :";
    temp -> right = BinaryTree();

    return temp;
}

void preorder(Node* root){
    if(root == NULL) return;

    stack<Node*> s;
    s.push(root);

    while(!s.empty()){
        Node* ptr = s.top();
        s.pop();
        cout<<" "<<ptr->val;
        if(ptr -> right != NULL){
            s.push(ptr->right);
        }

        if(ptr -> left != NULL){
            s.push(ptr->left);
        }
    }
}


int main(){
    Node* root;

    cout<<"Enter the root node:";
    root = BinaryTree();

    cout<<"Preorder traversal: ";
    preorder(root);

    return 0;
}