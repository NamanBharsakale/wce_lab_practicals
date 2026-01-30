#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node *right,*left;
    public:
    Node(int data){
        right = NULL;
        left = NULL;
        val = data;
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

int main(){
    cout<<"Enter the root of Binary tree: ";
    Node *root;
    root = BinaryTree();
}