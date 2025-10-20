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

void postorder(Node* root){
    if(!root) return;

    stack<Node*> s1,s2;

    Node* ptr = root;

    s1.push(ptr);

    while(!s1.empty()){
        ptr = s1.top();
        s1.pop();
        s2.push(ptr);

        if(ptr -> left)
        {
            s1.push(ptr->left);
        }
        if(ptr->right){
            s1.push(ptr -> right);
        }
    }

    while (!s2.empty())
    {
        ptr = s2.top();
        s2.pop();
        cout<<" "<<ptr->val;
    }
    
}
int main(){
    Node* root;

    cout<<"Enter the root node:";
    root = BinaryTree();

    cout<<"Postorder traversal: ";
    postorder(root);

    return 0;
}