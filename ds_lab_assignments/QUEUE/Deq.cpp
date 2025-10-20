#include <iostream>
using namespace std;

#define MAX 10
class Dq{
    public:
    int arr[MAX];
    int rear,front;

    public:
    Dq(){
        front = -1;
        rear = -1;
    }

    bool isFull(){
        return (front == 0 && rear == MAX -1 )||( front == rear + 1);
    }
    bool isEmpty(){
        return (front == -1);
    }

    void insertFront(int data){
        if(isFull()){
            cout<<"Queue is full";
            return;
        }
        if(isEmpty()){
            front = 0;
            rear = 0;
        }else if(front == 0){
            front = MAX -1;
        }
        else{
            front = front - 1;
        }
        arr[front] = data;
        cout<<data<<" inserted at front.."<<endl;
        return;
    }

    void insertRear(int data){
        if(isFull()){
            cout<<"Queue is Full";
            return;
        }

        if(isEmpty()){
            front = 0;
            rear = 0;
        }
        else if(rear == MAX - 1){
            rear = 0;
        }
        else{
            rear  = rear + 1;
        }

        arr[rear] =data;
        cout<<data<<" inserted at rearr.."<<endl;
        return;        
    }

    void deleteFront(){
        if(isEmpty()){
            cout<<"Queue is Empty..";
            return;
        }
        cout<<arr[front]<<" is deleted.."<<endl;
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else if(front == MAX -1){
            front  = 0;
        }
        else{
            front = front + 1;
        }
    }

    void deleteRear(){
        if(isEmpty()){
            cout<<"Queue is EMpty..";
            return;
        }

        cout<<arr[rear]<<" is deleted.."<<endl;

        if(rear == front){
            front = -1;
            rear = -1;
        }
        else if(rear == 0 ){
            rear = MAX -1;
        }
        else{
            rear = rear - 1;
        }
    }

    void display(){
        if(isEmpty()){
            cout<<"Queue is empty..";
            return;
        }

        int i = front;
        while (true)
        {
            cout<<arr[i]<<" ";
            if( i == rear )
                break;
            
            i = ( i + 1 ) % MAX;
        }
        
        cout<<endl;
    }
};
int main(){
    Dq dq;
    dq.insertFront(19);
    dq.insertFront(30);
    dq.display();
    dq.insertRear(22);
    dq.display();
    dq.insertRear(90);
    dq.display();
    dq.deleteFront();
    dq.display();
    dq.deleteRear();
    dq.display();
    
}