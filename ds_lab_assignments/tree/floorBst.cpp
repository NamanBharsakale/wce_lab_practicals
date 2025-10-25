#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    public: 
    Node(int data){
        val = data;
        right = nullptr;
        left = nullptr;
    }
};

Node* insertBst(Node* root, int data){

    if(!root){
        return new Node(data);
    }
    else{
        if(data < root->val){
            root -> left = insertBst(root->left,data);
        }
        else if(data > root -> val){
            root -> right = insertBst(root -> right,data);
        }
    }
    return root;
}

int floorBst(Node* root, int key){
    if(!root) return -1;
    
    int floor = -1;
    while(root != NULL){
        if(key == root -> val){
            floor = root->val;
            return floor;
        }
        else if(key < root->val){
            root = root -> left;
        }
        else{
            floor = root -> val;
            root = root -> right;
        }
    }
    return floor;
}
int main(){
    Node* root = NULL;
    int data,n;
    cout<<"How many nodes you want to insert: ";
    cin>>n;
    for(int i =0 ; i< n; i++){
        cout<<"Enter the "<<i+1<<" node: ";
        cin>>data;
        root = insertBst(root, data);
    }

    cout<<"Enter key: ";
    cin>>data;

    cout<<"Floor of "<<data<<" : "<<floorBst(root,data);

    return 0;

}