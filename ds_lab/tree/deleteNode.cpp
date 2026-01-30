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
        right = NULL;
        left = NULL;
    }
};

Node* insert_bst(Node* root,int item)
{
    if(!root){
        return new Node(item);
    }
    else{
        if(root -> val > item){
            root -> left = insert_bst(root->left,item);
        }


        if(root -> val < item){
            root -> right = insert_bst(root->right,item);
        }
    }

    return root;
}

void inorder(Node* root){
    if(!root) return;

    inorder(root->left);
    cout<<" "<<root->val;
    inorder(root->right);
}

Node* delBst(Node* root, int data){
    if(!root) return NULL;

    if(data < root -> val){
        root -> left = delBst(root -> left,data);
    }
    else if(data > root -> val){
        root -> right = delBst(root -> right,data);
    }
    else{
        //both does not exists
        if(root -> right == NULL && root -> left == NULL){
            delete root;
            return NULL;
        }
        else{
            //means left exists ,not right
            if(!root -> right){
                Node* temp = root -> left;
                delete root;
                return temp;
            }
            //means right exists, not left
            if(!root -> left){
                Node* temp = root -> right;
                delete root;
                return temp;
            }

            Node* child = root->left;
            Node* parent = root;
            while(child -> right != NULL){
                parent = child;
                child = child -> right;
            }

            if(parent != root){
                parent->right = child->left;
                child -> left = root->left;
                child -> right = root->right;
                delete root;
                return child;
            }

            if(parent == root){
                child->right = root -> right;
                delete root;
                return child;
            }

        }
    }
    return root;
}
int main(){

    Node* root = nullptr;
    int n, data;
    cout<<"How many nodes you want to store: ";
    cin>>n;
    for(int i = 0; i< n; i++){
        cout<<"Enter the "<<i+1<<" node : ";
        cin>>data;
        root= insert_bst(root,data);
    }

    cout<<"Before deleting inorder: ";
    inorder(root);

    cout<<"Enter the node to delete: ";
    cin>>data;
    root= delBst(root, data);

    cout<<"After deleting inorder: ";
    inorder(root);

    return 0;

}