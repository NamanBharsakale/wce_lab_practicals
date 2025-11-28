#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* right;
    Node* left;

    public:
    Node(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

Node* insertBst(Node* root,int data){
    if(!root){
        return new Node(data);
    }
    else{
        if(data > root -> val){
            root -> right = insertBst(root -> right, data);
        }
        else if(data <= root -> val){
            root -> left = insertBst(root -> left, data);
        }
    }
    return root;
}

bool searchBst(Node* root, int data){
    if(!root) return false;

    if(data == root -> val){
        return true;
    }
    else if(data > root -> val){
        return (searchBst(root -> right, data));
    }
    else if(data < root -> val){
        return (searchBst(root -> left,data));
    }

    return false;
}

int main(){
    Node* root = NULL;
    int data,n;

    cout<<"How many nodes to insert: ";
    cin>>n;

    for(int i = 0; i < n; i++){
        cout<<"Enter the "<<i+1<<" node : ";
        cin>>data;
        root = insertBst(root,data);
    }

    cout<<"Enter node to be search : ";
    cin>>data;

    if(searchBst(root,data)){
        cout<<"Found it..";
    }
    else{
        cout<<"Not found..";
    }

    return 0;
}