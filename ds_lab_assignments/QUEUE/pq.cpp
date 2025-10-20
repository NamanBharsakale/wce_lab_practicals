#include <iostream>
using namespace std;
#define MAX 10

struct ITEM{
    int data;
    int pr;//priority
};


class PriorityQueue{
    public:
    ITEM arr[MAX];
    int rear,front;

    public:
    PriorityQueue(){
        front = -1;
        rear = -1;
    }

    bool isFull(){
        return (rear == MAX -1);
    }

    bool isEmpty(){
        return (front == -1);
    }

    void enqueue(int data,int priority){
        if(isFull()){
            cout<<"Qurue is full..";
            return;
        }

        if(rear == -1 && front == -1){
            rear = 0;
            front = 0;
            arr[rear].data = data;
            arr[rear].pr = priority;
        }else{
            
        int i = rear;
        while (i >= front && arr[i].pr > priority)
        {
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i+1].data = data;
        arr[i+1].pr = priority;

        }
        cout<<data<<" Inserted.."<<endl;        rear = rear + 1;
        return;
        
    }

    void deque(){
        if(isEmpty()){
            cout<<"Queue is empty..";
            return;
        }

        cout<<arr[front].data<<" deleted.."<<endl;
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

        for(int i = front; i < rear; i++){
            cout<<arr[i].data<<" ";
        }
        cout<<endl;
    }
    
};
int main(){
    PriorityQueue pq;
    pq.enqueue(10,3);
    pq.enqueue(56,2);
    pq.enqueue(23,4);
    pq.enqueue(11,1);
    pq.display();
    pq.deque();
    pq.display();

    return 0;

}