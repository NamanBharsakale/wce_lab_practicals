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
        newNode -> next = head;
        cout<<"Inserted at end"<<endl;
    }


    void deleteAtStart(){
        if(head == NULL){
            cout<<"LinkedList is empty..";
            return;
        }
        Node* temp = head;
        while(temp -> next != head){
            temp = temp -> next;
        }

        head = head -> next;
        temp -> next = head;


        cout<<"deleted .."<<endl;
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
        prev -> next = head;
        delete temp;
        cout<<"Deleted at the end"<<endl;
    }

    void deleteNext(Node* d){
        if(d -> next == head){
            Node* temp = head;
            Node* sl = head;
            while(sl -> next != head){
                sl = sl -> next;
            }
            head = head -> next;
            sl -> next =head;

            delete temp;
            return;
        }
        Node* temp = d -> next;
        d -> next =temp -> next;
        delete temp;
        return;
    }
    void display(){
        if(head == NULL){
            cout<<"Linked list is empty..";
            return;
        }
        Node* temp = head;
        while(temp != head){
            cout<<temp->data<<" -> ";
            temp = temp -> next;
        }
    }

    

    void deleteEven(){
        if(head== NULL){
            cout<<"Linked List is empty..";
            return;
        }

        int i = 0;
        Node* temp = head;
        while(temp -> next != NULL){
            if(i % 2 == 1){
                deleteNext(temp);
            }
            temp = temp -> next; 
            i++;
        }
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
        cout<<"5.Delete at even: "<<endl;
        cout<<"6.Delete at end: "<<endl;
        cout<<"7.Display"<<endl;
        cout<<"8.-"<<endl;
        cout<<"9.-: "<<endl;
        cout<<"10.Exit: "<<endl;
        cout<<"Enter the choice: "<<endl;
        cin>>ch;

        switch (ch)
        {
        
        case 1:cin>>data;
        l.insertAtStart(data);break;
        case 2:;break;
        case 3:cin>>data;
        l.insertAtEnd(data);break;
        case 4:l.deleteAtStart();break;
        case 5:cin>>pos;
        l.deleteEven();break;
        case 6:l.deleteAtEnd();break;
        case 7:l.display();break;
        case 8:;break;
        case 9:;break;
        case 10:flag = false;break;

        
        default:
            break;
        }
    }
}