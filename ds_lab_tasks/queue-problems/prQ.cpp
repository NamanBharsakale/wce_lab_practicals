#include <iostream>
using namespace std;

#define MAX 100
struct ITEM{
    int val;
    int priority;
};

class PriorityQueue{
    ITEM pq[MAX];
    int rear,front;

    public:
    PriorityQueue(){
        rear = -1;
        front = -1;
    }

    void enqueue(int val,int pr){
        if(rear == MAX - 1){
            cout<<"Overflow.";
            return;
        }

        if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
            pq[rear].val = val;
            pq[rear].priority = pr;
            return;
        }

        int i = rear;
        while(i >= front && pq[i].priority > pr){
            pq[i+1] = pq[i];
            i = i -1;
        }
        pq[i+1].val = val;
        pq[i+1].priority = pr;
        rear = rear + 1;
    }

    void dequeue(){
        if(front == -1){
            cout<<"Underflow..";
            return;
        }
        if(front == rear){
            front = 0;
            rear = 0;
        }
        else{
            front = front + 1;
        }
        cout<<"Deleted..";

    }
    void display(){
        if(front == -1){
            cout<<"Empty...";
            return;
        }
        for(int i = front; i <= rear; i++){
            cout<<" ("<<pq[i].val<<","<<pq[i].priority<<")"<<endl;;
        }

    }

};
int main(){
    PriorityQueue pq;
    pq.enqueue(10,1);
    pq.enqueue(80,2);
    pq.enqueue(22,4);
    pq.enqueue(11,3);
    pq.display();
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    pq.display();

    return 0;
}