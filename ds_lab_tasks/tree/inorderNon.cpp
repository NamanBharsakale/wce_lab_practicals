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

void inorder(Node* root){
    if(!root) return;

    stack<Node*> s;
    Node* ptr = root;

    while (ptr != NULL || !(s.empty()))
    {
        while (ptr!= NULL)
        {
            s.push(ptr);
            ptr = ptr -> left;
        }

        if(ptr == NULL && !(s.empty())){
            ptr = s.top();
            s.pop();

            cout<<" "<<ptr->val;

            ptr = ptr -> right;
        }
        
    }
    
}
int main(){
    Node* root;

    cout<<"Enter the root node:";
    root = BinaryTree();

    cout<<"Inorder traversal: ";
    inorder(root);

    return 0;
}