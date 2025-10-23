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

Node* BinaryTree(){
    int x;
    cin>>x;

    if(x == -1) return NULL;

    Node* temp = new Node(x);
    cout<<"Enter the left child of "<<x<<" : ";
    temp -> left = BinaryTree();
    cout<<"Enter the right child of "<<x<<" : ";
    temp -> right = BinaryTree();

    return temp;
}


void inorder(Node* root){
    if(!root) return;

    inorder(root -> left);
    cout<<" "<<root -> val;
    inorder(root -> right);

}

int heightBt(Node* root){
    if(!root) return 0;

    int left = heightBt(root -> left);
    int right = heightBt(root -> right);

    int max = left > right ? left : right;
    return (1 + max );
}

bool balancedBt(Node* root){
    if(!root) { 
        return true;
    }
    
    int left_height = heightBt(root->left);
    int right_height = heightBt(root->right);

    int diff = left_height - right_height;

    if(!(diff <= 1 && diff >= -1)) return false;

    bool left = balancedBt(root -> left);
    bool right = balancedBt(root -> right);

    if(!left || !right) return false;

    return true;
}
int main(){
    Node* root = nullptr;

    cout<<"ENter the root node: ";
    root = BinaryTree();

    cout<<"Inorder Traversal : ";
    inorder(root);
    cout<<endl;

    cout<<"Height of tree is: "<<heightBt(root)<<endl;
    if(balancedBt(root)){
        cout<<"yes , it is a balanced tree..";
    }
    else{
        cout<<"No, it is not a balanced tree..";
    }
    return 0;


}