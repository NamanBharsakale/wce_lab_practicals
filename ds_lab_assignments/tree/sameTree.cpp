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
        right = NULL;
        left = NULL;
    }
};

bool sameTree(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL) {
        return true;
    }
    else if(root1 == NULL || root2 == NULL){
        return false;
    }

    return (root1->val == root2->val && sameTree(root1->left,root2->left) && sameTree(root2->right,root2->right));
}
int main(){
    Node* root1;
    Node* root2;

    root1 = new Node(10);
    root1 -> left = new Node(20);
    root1 -> left -> left = new Node(21);
    root1 -> right =new Node(30);
    root1 -> right -> left =new Node(22);

    root2 -> val = 10;
    root2 -> left = new Node(20);
    root2 -> left -> left = new Node(21);
    root2 -> right = new Node(30);
    root2 -> right -> left = new Node(22);

    if(sameTree(root1,root2)){
        cout<<"yes, both tree are same";
    }
    else{
        cout<<"No, both tree are not same";
    }

    return 0;
}