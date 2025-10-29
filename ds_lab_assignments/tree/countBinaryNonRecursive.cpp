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

int CountNode(Node* root){
    stack<Node*> s;
    s.push(root);
    int count = 0;

    while(!s.empty()){
        Node* node = s.top();
        s.pop();

        count++;

        if(node->left){
            s.push(node->left);
        }

        if(node->right){
            s.push(node->right);
        }
    }

    return count;
}

int main(){
    Node * root;
    root = BinaryTree();

    cout<<"Preorder COunt of Nodes: "<<CountNode(root);
   
    return 0;
}