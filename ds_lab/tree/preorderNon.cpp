#include <iostream>
#include <stack>
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

Node* BinaryTree(){
    int x;
    cin>>x;

    if(x == -1) return NULL;

    Node* temp = new Node(x);
    cout<<"Enter the left child of "<<x<<" :";
    temp -> left = BinaryTree();
    cout<<"Enter the right child of "<<x<<" : ";
    temp -> right = BinaryTree();

    return temp;
}

void preorder(Node* root){

    if(!root) return;

    stack<Node*> s;
    s.push(root);

    while(!s.empty()){
        Node* ptr = s.top();
        s.pop();

        cout<<" "<<ptr -> val;

        if(ptr -> right){
            s.push(ptr->right);

        }

        if(ptr -> left){
            s.push(ptr -> left);
        }
    }

}

int main(){
    Node* root = NULL;

    cout<<"Enter the root node: ";
    root = BinaryTree();

    cout<<"Preorder Traversal: ";
    preorder(root);
    return 0;
}