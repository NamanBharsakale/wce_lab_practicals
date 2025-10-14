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

bool preorderSearch(Node* root,int data){
    if(root == NULL) return false;
    
    if(root -> val == data){
        return true;
    }
    if(preorderSearch(root->left, data)) return true;
    if(preorderSearch(root->right, data)) return true;

    return false;
}

int main(){
    cout<<"Enter the root of Binary tree: ";
    Node *root;
    root = BinaryTree();

    int data;

    cout<<"ENter the data to be searched: ";
    cin>>data;
    if(preorderSearch(root,data)){
        cout<<"Found it..";
    }
    else{
        cout<<"Not found...";
    }
    

    return 0;
}