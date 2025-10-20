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
        return (rear == MAX -1);
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
        }

        if(front == 0){
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
        cout<<data<<" insertde at rearr.."<<endl;
        return;        
    }

    void display(){
        if(isEmpty()){
            cout<<"Queue is empty..";
            return;
        }

        for(int i =front;i<=rear; i++){
            cout<<" "<<arr[i];
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
}