#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    public:
    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoubleLinkedList{
    public:
    Node* head;
    public:
    DoubleLinkedList(){
        head = NULL;
    }

    void insertAtBeginning(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            cout<<"Inserted at Beg..";
            return;
        }
        else{
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
        cout<<"Inserted at Beg..";
    }

    void insertAtEnd(int val){
        if(head == nullptr){
            insertAtBeginning(val);
            return;
        }
        else{
            Node* temp = head;
            while(temp -> next != nullptr){
                temp = temp -> next;
            }

            Node* newNode = new Node(val);
            temp -> next = newNode;
            newNode -> prev = temp;
            newNode -> next = nullptr;
        }
        cout<<"Inserted At the end.."<<endl;
    }

    void insertAtPosition(int value, int pos){
        if(head == NULL && pos <= 1){
            insertAtBeginning(value);
            return;
    }
    else{
            Node* temp = head;

            for(int i = 1; i < pos -1;i++){
                temp = temp -> next;
            }

            Node* newNode = new Node(value);
            newNode -> next = temp -> next;
            if(temp ->next != NULL){
                temp -> next -> prev = newNode;
            }
            temp -> next = newNode;
            newNode -> prev = temp;
        }
        cout<<"Inserted at pos "<<pos<<endl;
    }

    void deleteFromBeginning(){
        if(head == NULL){
            cout<<"List is empty.."<<endl;
            return;
        }
        Node* temp = head;
        head = head -> next;
        head -> prev = NULL;

        delete temp;
        cout<<"Deleted from beginnning..";
    }

    void deleteFromEnd(){
        if(head == NULL)
        {
            cout<<"List is empty.."<<endl;
            return;
        }
        
        Node* temp = head;
        Node* pre = NULL;
        while(temp -> next != nullptr){
            pre = temp;
            temp = temp -> next;
        }
        pre -> next = NULL;
        delete temp;
        cout<<"Deleted from the end."<<endl;

    }

    void deleteFromPosition(int pos)
    {
        if(pos <= 1){
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for(int i = 1; i < pos && temp != NULL; i++){
            temp = temp -> next;
        }

        if(temp == NULL){
            cout<<"Position outof bound..";
            return;
        }

        if(temp -> prev != NULL){
            temp -> prev -> next = temp -> next;
        }

        if(temp -> next != NULL){
            temp -> next -> prev = temp -> prev;
        }
        delete temp;
        cout<<"Deleted .. "<<endl;
    }

    void displayList(){
        if(head == NULL){
            cout<<"List is empty..";
            return;
        }

        Node* temp = head;
        while(temp != nullptr){

            cout<<""<<temp->data;
            if(temp -> next != nullptr) cout<<" <-> ";

            temp = temp -> next;

        }
    }
};

int main(){
    int choice, value, pos;
    DoubleLinkedList dl;

    while (true) {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dl.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                dl.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                dl.insertAtPosition(value, pos);
                break;
            case 4:
                dl.deleteFromBeginning();
                break;
            case 5:
                dl.deleteFromEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                dl.deleteFromPosition(pos);
                break;
            case 7:
                dl.displayList();
                break;
            case 8:
                cout << "Exiting program.\n";
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0; 
}