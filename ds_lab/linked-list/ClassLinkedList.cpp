#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int val){
        data = val;
        next = nullptr;
    }
};
class LinkedList{
    public:
    Node* head;
    public:
    LinkedList(){
        head = NULL;
    }

    void insertAtStart(int val){
        Node* newNode = new Node(val);
        newNode -> next = head;
        head = newNode;
        cout<<"Node inserted at start..";
    }

    void insertAtEnd(int val){
        if(head == NULL){
            insertAtStart(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> next = NULL;
        cout<<"Inserted at end"<<endl;
    }

    void insertAtPos(int val,int pos){
        if(head == NULL && pos <= 1){
            insertAtStart(val);
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for(int i = 0; i < pos - 1; i++){
            temp = temp -> next;
        }

        newNode -> next = temp -> next;
        temp -> next = newNode;
        cout<<"Inserted at position "<<pos<<endl;
    }

    void deleteAtStart(){
        if(head == NULL){
            cout<<"LinkedList is empty..";
            return;
        }
        Node* temp = head;
        head = head -> next;
        cout<<"deleted .."<<endl;
        delete temp;
    }

    void deleteAtEnd(){
        if(head == NULL){
            cout<<"Linked List is empty..";
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        while(temp -> next != NULL){
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = NULL;

        delete temp;
        cout<<"Deleted at the end"<<endl;
    }

    void deleteAtPos(int pos){
        if(head == NULL && pos <= 1){
            cout<<"Linked is Empty.";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;
        for(int i = 1; i < pos -1 ; i++){
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = temp -> next;

        delete temp;
        cout<<"Deleteed at position"<<pos<<endl;
    }

    void deletePos(int pos){
        if(head == NULL){ cout<<"Linked List is empty..";}
        if(pos == 1){ deleteAtStart();}

        Node* temp  = head;
        Node* prev = NULL;

        for(int i = 1; i < pos - 1; i++){
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = temp -> next;
        delete temp;
        cout<<"Deleted at "<<pos<<endl;
    }

    void display(){
        if(head == NULL){
            cout<<"Linked list is empty..";
            return;
        }
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp -> next;
        }
    }

    void reverse(){
        if(head == NULL){ 
            cout<<"Linked List is empty..";
        }

        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;

        while(current != NULL){
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
            
        }
        head = prev;
    }

    void FindMid(){
        if(head == NULL){
            cout<<"Linked List is empty..";
            return;
        }

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        cout<<"Middle of Linked List: "<<slow->data<<endl;

        delete slow;
        delete fast;
        return;
    }
};
int main(){
    LinkedList l;

    bool flag = true;

    while(flag){
        int ch,data,pos;
        cout<<"\n-----Linked List Operations-------"<<endl;
        cout<<"1.Insert at start: "<<endl;
        cout<<"2.Insert at Pos: "<<endl;
        cout<<"3.Insert at end: "<<endl;
        cout<<"4.Delete at Start: "<<endl;
        cout<<"5.Delete at pos: "<<endl;
        cout<<"6.Delete at end: "<<endl;
        cout<<"7.Display"<<endl;
        cout<<"8.Reverse"<<endl;
        cout<<"9.Find middle: "<<endl;
        cout<<"10.Exit: "<<endl;
        cout<<"Enter the choice: "<<endl;
        cin>>ch;

        switch (ch)
        {
        
        case 1:cin>>data;
        l.insertAtStart(data);break;
        case 2:cin>>pos>>data;
        l.insertAtPos(data,pos);break;
        case 3:cin>>data;
        l.insertAtEnd(data);break;
        case 4:l.deleteAtStart();break;
        case 5:cin>>pos;
        l.deleteAtPos(pos);break;
        case 6:l.deleteAtEnd();break;
        case 7:l.display();break;
        case 8:l.reverse();break;
        case 9:l.FindMid();break;
        case 10:flag = false;break;

        
        default:
            break;
        }
    }
}