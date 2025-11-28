#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    static Node* head;
    public:
    
    Node* createNode(int data){
        Node* newNode = new Node;
        newNode -> val = data;
        newNode -> prev = nullptr;
        newNode -> next = nullptr;
        return newNode;
    }

    void insertAtBeg(int val){
        Node* newNode = createNode(val);
        if(head == nullptr){
            head = newNode;
        }else
        {
            newNode->next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }
    void insertAtEnd(int val){
        Node* newNode = createNode(val);
        if(head == nullptr){
            insertAtBeg(val);
        }else{
            Node* temp = head;
            while(temp -> next != nullptr){
                temp = temp -> next;
            }
            temp->next = newNode;
            newNode -> prev = temp;
            newNode -> next = nullptr;
        }
    }

    void insertAtPos(int pos, int val){
        if(pos <= 1){
            insertAtBeg(val);
            return;
        }
        Node* newNode = createNode(val);
        Node* temp = head;
        for(int i = 0;temp -> next !=nullptr && i < pos-1;i++){
            temp = temp -> next;
        }
        newNode -> prev = temp;
        newNode -> next = temp -> next;
        temp -> next -> prev = newNode;
        temp -> next = newNode;

    }

    void display(){
        if(head == nullptr){
            cout<<"Empty Liked List...";
            return;
        }
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->val<<" ";
            temp = temp -> next;
        }
        return;
    }
};


Node* Node::head = nullptr;
int main() {
    Node node;
    while (true) {
        int choice, pos, value;

        // Print the menu every time
        cout << "\nChoose the option:\n";
        cout << "1. Insert At Beginning\n";
        cout << "2. Insert At End\n";
        cout << "3. Insert At Position\n";
        cout << "4. Delete From Beginning\n";
        cout << "5. Delete From End\n";
        cout << "6. Delete From Position\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;


        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                node.insertAtBeg(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                node.insertAtEnd(value);
                break;
            case 3:

                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                node.insertAtPos(pos, value);  // implement this method
                break;

            case 4:
                // call deleteFromBeg if implemented
                break;
            case 5:
                // call deleteFromEnd if implemented
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                // call deleteAtPos if implemented
                break;
            case 7:
                node.display();
                break;
            case 8:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
