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
        left = NULL;
        right = NULL;
    }
};

Node* insert_bst(Node* root, int item){
    if(!root){
        return new Node(item);
    }
    else{
        if(item > root->val){
            root -> right = insert_bst(root->right,item);
        }
        else{
            root -> left = insert_bst(root->left,item);
        }
    }
    return root;
}

void minBst(Node* root){
    if(!root) return;

    Node* current = root;
    current = current -> left;

    while (current -> left != NULL)
    {
        current = current -> left;
    }
    
    cout<<"Minimum value is "<<current -> val;
}
void inorder(Node* root){
    if(!root) return;

    inorder(root->left);
    cout<<" "<<root->val;
    inorder(root->right);
}

int main(){
    Node* root = NULL;
    int n,data;
    cout<<"Enter number nodes want to insert: ";
    cin>>n;
    for(int i = 0; i<n;i++){
        cout<<"Enter the "<<i+1<<" node:";
        cin>>data;
        root = insert_bst(root,data);
    }

    cout<<"Inorder Traversal of BST: ";
    inorder(root);
    cout<<endl;
    minBst(root);

    return 0;
}