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
        left = nullptr;
        right = nullptr;
    }
};

Node* insert_bst(Node* root,int data){
    if(!root){
        return new Node(data);
    } else{

        if(data > root -> val){
            root -> right = insert_bst(root->right,data);
        }
        else{
            root -> left = insert_bst(root->left,data);
        }
    }

    return root;

}

Node* delBst(Node* root,int data){
    if(!root) return NULL;

    if(data > root -> val){
        root -> right = delBst(root -> right,data);
    }
    else if(data < root -> val){
        root -> left = delBst(root -> left, data);
    }
    else{

        //No child exists
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        else{
            //one child exist
            //Left exists
            if(!root->right){
                Node* temp =  root -> left;
                delete root;
                return temp;
            }

            //right exists
            if(!root->left){
                Node* temp = root -> right;
                delete root;
                return temp;
            }

            //Left and right both exists
            Node* child = root -> left;
            Node* parent = root;
            
            while(child -> right != NULL){
                parent = child;
                child = child -> right;
            }

            if(parent != root){
                parent -> right = child -> left;
                child -> left = root -> left;
                child -> right = root -> right;
                delete root;
                return child;
            }

            if(parent == root){
                child -> right = root -> right;
                delete root;
                return child;
            }
        }
    }

    return root;
}

void inorder(Node* root){
    if(!root) return;

    inorder(root->left);
    cout<<" "<<root -> val;
    inorder(root -> right);
}

int main()
{
    Node* root = nullptr;
    int n;
    cout<<"Enter How many node want to insert: ";
    cin>>n;
    int data;

    for(int i = 0; i < n; i++){
        cout<<"Enter "<<i+1<<" nodes: ";
        cin>>data;
        root = insert_bst(root,data);
    }

    cout<<"Inorder traversal before deletion: ";
    inorder(root);

    cout<<"Enter the node to delete: ";
    cin>>data;
    root = delBst(root,data);

    cout<<"Inorder traversal after deletion: ";
    inorder(root);

    return 0;
}