#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int val;
    Node *left;
    Node *right;
    public:
    Node(int data){
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

Node* BinaryTree(){
    int x;
    cin>>x;

    if(x == -1) return nullptr;
    Node* temp = new Node(x);
    cout<<"Enter the Left CHild of "<<x<<":";
    temp ->left = BinaryTree();
    cout<<"Enter the Right Child of "<<x<<":";
    temp ->right = BinaryTree();


    return temp;

}

void inorder(Node* root,vector<int> &arr){
    if(!root) return;

    inorder(root -> left,arr);
    arr.push_back(root -> val);
    inorder(root -> right, arr);
}

bool isBst(Node* root){
    vector<int> arr;
    inorder(root,arr);
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] < arr[i-1]) return false;
    }
    return true;

}

int main(){
    cout<<"ENter the root node:";
    Node* root;
    root = BinaryTree();

    if(!isBst(root)){
        cout<<"No, It is not BST";
    }
    else{
        cout<<"Yes ,it is found .it is BST";
    }
}