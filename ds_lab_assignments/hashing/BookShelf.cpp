#include <iostream>
#include <string>
using namespace std;

class Book{
    public:
    string str;
    Book* next;
    public:
    Book(string s){
        str = s;
        next = nullptr;
    }
};
class BookShelf{
    public:
    Book** shelf;
    int size;
    public:
    BookShelf(int s){
        size = s;
        shelf = new Book*[size];
        for(int i = 0; i < size; i++){
            shelf[i] = NULL;
        }
    }

    int hashFunction(str val){
        return val % size;
    }

    void insertBook(string b){
        int index = hashFunction(b);
        Book* newNode = new Book(s);
        if(shelf[index] == NULL){
            shelf[index] = newNode;
        }
        else{
            Book* temp = shelf[index];
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
            cout<<val<<"Inserted at "<<index;
        }
    }

    bool search(string sr){
        int index = hashFunction(sr);
        Book* temp = shelf[index];
        while(temp != NULL){
            if(temp -> str == sr){
                return true;
            }
            temp = temp -> next;
        }
        return false;
    }

    void display(){
        for(int i = 0; i < size; i++){
            Book* temp = shelf[i];
            while(temp != NULL){
                cout<<temp -> str<<" : ";
                if(temp -> next != NULL) cout<<" -> ";
                temp = temp -> next;
            }
            cout<<endl;
        }
    }

};
int main(){
    int size;
    cout<<"Enter the size of bookshelf : ";
    cin>>size

    BookShelf b(size);
    bool flag = true;

    while(flag){
        cout<<"1. Insert:"<<endl;
        cout<<"2. search: "<<endl;
        cout<<"3. display: "<<endl;
        int opt;
        string str;
        cout<<"Enter the option: ";
        cin>>opt;
        switch (opt)
        {
        case 1:
            cin>>str;
            b.insertBook(str);
            break;

        case 2:
            cin>>str;
            if(b.search(str)){
                cout<<"Found"<<endl;
            }
            else{
                cout<<"Not Found.."<<endl;
            }
            break;

        case 3:b.display();break;
        case 4: flag = false;break;

        
        default:
            break;
        }

    }
}