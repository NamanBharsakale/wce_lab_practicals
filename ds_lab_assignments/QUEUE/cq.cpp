#include <iostream>
using namespace std;
#define MAX 5
class cq{
    public:
    int arr[MAX];
    int front, rear;

    public:
    cq(){
        front = -1;
        rear = -1;
    }

    bool isFull(){
        return ((rear + 1)%MAX == front);
    }

    bool isEmpty(){
        return (front == -1);
    }

    void enqueue(int data){
        if(isFull()){
            cout<<"Queue is Full";
            return;
        }

        if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
        }
        else{
            rear = (rear + 1)%MAX;
        }
        arr[rear] = data;
        cout<<data<<" inserted "<<endl;
        return;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty..";
            return;
        }

        cout<<arr[front]<<" deleted.."<<endl;
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front+1)%MAX;
        }
        return;
    }

    void display(){
        if(isEmpty()){
            cout<<"Queue is empty..";
            return;
        }

        for(int i = front; i <= rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
};

int main(){
    cq q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();

    
}