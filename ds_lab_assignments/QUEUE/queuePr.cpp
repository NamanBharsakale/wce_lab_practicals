#include <iostream>
using namespace std;
#define MAX 10
class queue{
    public:
    int arr[MAX];
    int front, rear;

    public:
    queue(){
        front = -1;
        rear = -1;
    }

    bool isFull(){
        return (rear == MAX - 1);
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
            rear = rear + 1;
        }
        arr[rear] = data;
        cout<<data<<" inserted";
        cout<<endl;
        return;
    }


    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty";
            return;
        }
        cout<<arr[front]<<" deleted..";
        cout<<endl;
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = front + 1;
        }
        return;
    }
    void display(){
        if(isEmpty()){
            cout<<"Queue is empty..";
            return;
        }

        for(int i = front; i <= rear ; i++){
            cout<<" "<<arr[i];
        }
        cout<<endl;

        return;
    }
};
int main(){
    queue q;
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(89);
    q.display();

    return 0;
}