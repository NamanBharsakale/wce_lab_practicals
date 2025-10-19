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

Node * BinaryTree(){
    int x;
    cin>>x;

    if(x == -1) return NULL;
    Node* temp = new Node(x);
    cout<<"Enter the left of "<<x<<": ";
    temp -> left = BinaryTree();
    cout<<"Enter the right of "<<x<<": ";
    temp -> right = BinaryTree();

    return temp;

}

void preorder(Node* root){
    stack<Node*> s;
    Node * current = root;

    while(true){
        while(current != NULL){
            cout<<" "<<current->val;
            s.push(current);
            current = current -> left;
        }
        if(s.empty()){
            break;
        }
        else{
            current = s.top();
            s.pop();
            current = current -> right;
        }
    }
}

void inorder(Node* root){
    stack<Node*> s;
    Node* current = root;
    while(true){
        while(current != NULL){
            s.push(current);
            current = current -> left;
        }
        if(s.empty()){
            break;
        }
        else{
            current = s.top();
            cout<<" "<<current->val;
            current = current -> right;
        }
    }
}

void postorder(Node* root){

}
int main(){
    Node* root;
    cout<<"Enter the root Data: "<<endl;
    root = BinaryTree();

    cout<<"Preorder Traversal : ";
    preorder(root);

    cout<<"Inorder Traveersal : ";
    inorder(root);

    return 0;
}