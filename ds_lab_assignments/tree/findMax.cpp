#include <iostream>
#include <climits>
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


Node* BinaryTree(){
    int x; 
    cin>>x;

    if(x==-1){
        return NULL;
    }

    Node* temp = new Node(x);
    cout<<"Enter the left child of "<<x<<" : ";
    temp -> left = BinaryTree();
    cout<<"Enter the right child of "<<x<<" : ";
    temp -> right = BinaryTree();

    return temp;
}

int findMax(Node* root){
    
    Node* temp = root;   
    int val,left,right;
    int max = INT_MIN;
    if(root!=NULL)
    {
        int data = temp ->val;
        left = findMax(temp -> left);
        right = findMax(temp -> right);

        if(left > right){
            max = left;
        }
        else{
            max = right;
        }

        if(data > max){
            max = data;
        }
        return max;

        
    }

}

int main(){
    Node* root;

    cout<<"Enter the root node: ";
    root = BinaryTree();

    cout<<"Maximum elemebt in Binary tree: "<<findMax(root);

    return 0;
}