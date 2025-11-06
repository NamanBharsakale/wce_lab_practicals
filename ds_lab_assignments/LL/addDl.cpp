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

    void display(){
        if(head == NULL){
            cout<<"List is empty";
            return;
        }

        Node* temp = head;

        do{
            cout<<temp -> data<<" : ";
            temp = temp -> next;
        }while(temp != NULL);


    }

    

};

DoubleLinkedList* add(Node* head1, Node* head2){
        if(head1 == NULL && head2 == NULL){
            return NULL;
        }

        if(head1 == NULL){
            DoubleLinkedList* d = new DoubleLinkedList();
            d->head = head2;
            return d;
        }

        if(head2 == NULL){
            DoubleLinkedList* d = new DoubleLinkedList();
            d->head = head1;
            return d;
        }

        Node* temp1 = head1;
        Node* temp2 = head2;

        DoubleLinkedList* d = new DoubleLinkedList();

        while(temp1 != NULL && temp2 != NULL){
            d->insertAtBeginning(temp1 -> data + temp2 -> data);
            temp1 = temp1 -> next;
            temp2  = temp2 -> next;
        }

        while(temp1 != NULL){
            d->insertAtBeginning(temp1->data);
            temp1 = temp1 -> next;
        }

        while(temp2 != NULL){
            d->insertAtBeginning(temp1->data);
            temp2 = temp2 -> next;
        }

        return d;

    }
int main(){
    int val,n1,n2;

    DoubleLinkedList dl1;
    DoubleLinkedList dl2;

    cout<<"Enter number of nodes you want to store in List1: ";
    cin>>n1;

    for(int i = 0; i < n1; i++){
        cin>>val;
        dl1.insertAtBeginning(val);
    }

    cout<<"Enter number of nodes you want to store in List2: ";
    cin>>n2;

    for(int i = 0; i < n2; i++){
        cin>>val;
        dl2.insertAtBeginning(val);
    }

    DoubleLinkedList* dl = add(dl1.head,dl2.head);

    dl->display();


}