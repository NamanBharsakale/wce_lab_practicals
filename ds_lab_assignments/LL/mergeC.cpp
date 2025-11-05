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

class CList{
    public:
    Node* head = nullptr;
    public:
    CList(){
        head = nullptr;
    }

    void insertEnd(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = newNode;
            newNode -> next = head;
            return;
        }

        Node* temp = head;
        while(temp -> next != head){
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> next = head;
    }

    void display(){
        if(head == NULL){
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

CList* merge(Node* head1,Node* head2){
    if(head1 == NULL){
        CList* l = new CList();
        l->head = head2;
        return l;
    }

    if(head2 == NULL){
        CList* l = new CList();
        l->head = head2;
        return l;
    }

    Node* temp1 = head1;
    while(temp1 -> next!= head1){
        temp1 = temp1 -> next;
    }

    Node* temp2 = head2;
    while(temp2 -> next != head2){
        temp2 = temp2 -> next;
    }

    temp1 -> next = head2;
    temp2 -> next = head1;

    CList* cl = new CList();
    cl->head = head1;
    return cl;

}
int main(){
    CList l1;
    CList l2;

    int n1,n2,data;

    cout<<"Enter numeber of nodes you want in List 1: ";
    cin>>n1;

    cout<<"Enter "<<n1<<" nodes :";
    for(int i = 0; i < n1; i++){
        cin>>data;
        l1.insertEnd(data);
    }

    cout<<"Enter numeber of nodes you want in List 2: ";
    cin>>n2;

    cout<<"Enter "<<n2<<" nodes :";
    for(int i = 0; i < n2; i++){
        cin>>data;
        l2.insertEnd(data);
    }

    cout<<"List1: ";
    l1.display();

    cout<<"List2: ";
    l2.display();

    CList* l = merge(l1.head,l2.head);

    cout<<"Merged List: ";
    l->display();

}