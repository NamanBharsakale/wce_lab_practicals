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
class HashTable{
    public:
    Node** table;
    int size;
    public:
    HashTable(int s){
        size = s;
        table = new Node*[s];

        for(int i = 0; i < size; i++){
            table[i] = NULL;
        }
    }

    int hashFunction(int key){
        return key % size;
    }

    void insert(int data){
        int index = hashFunction(data);
        Node* newNode = new Node(data);

        if(table[index] == NULL){
            table[index] = newNode;
        }
        else{
            Node* temp = table[index];
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
            cout<<data<<" Inserted At "<<index<<endl;
        }
    }

    bool search(int val){
        int index = hashFunction(val);
        Node* temp = table[index];
        while(temp != NULL){
            if(temp -> data == val){
                return true;
            }

            temp = temp -> next;
        }

        return false;
    }

    void deleteN(int val){
        int index = hashFunction(val);
        Node* temp = table[index];
        Node* prev = NULL;

        while(temp != NULL){
            if(temp -> data == val){

                if(prev == NULL){
                    table[index] = temp -> next;
                }
                else{
                    prev -> next = temp -> next;
                }
                delete temp;
                cout<<val<<" deleted from "<<index<<endl;
                return;

            }
            prev = temp;
            temp = temp -> next;
        }
        cout<<"Not found to delete.."<<endl;
    }

    void display(){
        cout<<"\n Hash Table \n";
        for(int i = 0; i < size; i++){
            Node* temp = table[i];
            while(temp != NULL){
                cout<<temp -> data<<" : ";
                if(temp->next != NULL) cout<<" -> ";
                temp = temp -> next;
            }
            cout<<endl;
        }
    }

};
int main(){
    int size;
    cout<<"Enter the size of hash table: ";
    cin>>size;

    HashTable h(size);

    bool flag = true;
    while(flag){
        
        int data;
        cout<<"--Hashing--"<<endl;
        cout<<"1. Insert: "<<endl;
        cout<<"2. Delete: "<<endl;
        cout<<"3. Search: "<<endl;
        cout<<"4.display: "<<endl;
        cout<<"5.exit: "<<endl;
        cout<<"Enter the option: ";
        int ch;
        cin>>ch;


        switch (ch)
        {
            
        case 1:cin>>data;
               h.insert(data);
               break;
        case 2:cin>>data;
               h.deleteN(data);
               break;

        case 3:cin>>data;
               if(h.search(data)) 
               {
                    cout<<"Found..";
                }
                else{
                    cout<<"Not Found..";
                }
               break;

        case 4:h.display();
                break;
        case 5:flag = false;break;

        
        default:
            break;
        }
    }
}