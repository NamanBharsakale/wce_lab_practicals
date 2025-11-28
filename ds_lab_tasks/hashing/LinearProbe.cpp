#include <iostream>
using namespace std;

class HashTable{
    public:
    int size;
    int* table;
    public:
    HashTable(int s){
        size = s;
        table = new int[size];
        for(int i = 0; i < size; i++){
            table[i] = -1;
        }
    }


    int hashFunction(int key){
        return key % size;
    }

    void insert(int val){
        int index = hashFunction(val);

        int i = 0;
        while((table[(index + i)%size] != -1) && (table[(index + i)%size] != -2) ){
            i++;
            if(i == size){
                cout<<"Hash Table is Full..";
                return;
            }
        }
        table[(index + i)%size] = val;
        cout<<val<<" inserted at "<<(index + i)%size<<endl;
    }

    void deleteN(int val){
        int index = hashFunction(val);
        int i = 0;
        while(table[(index + i) % size] != -1){
            if(table[(index + i) % size] == val){
                table[(index + i) % size] = -2;
                cout<<val<<" deleted "<<index+i<<endl;
            }
            i++;
            if(i == size){
                break;
            }
        }
        cout<<"Key Not found.";
    }

    bool search(int val){
        int index = hashFunction(val);
        int i = 0;
        while(table[(index + i) % size] != -1){
            if(table[(index + i) % size] == val){
                return true;
            }
            i++;
            if(i == size){
                break;
            }
        }
        return false;
    }

    void display(){
        for(int i = 0 ; i < size; i++){
            if(table[i] == -1){
                cout<<i<<" {Empty}"<<endl;
            }
            else if(table[i] == -2){
                cout<<i<<" {Empty}"<<endl;
            }
            else{
                cout<<i<<" : "<<table[i]<<endl;
            }
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