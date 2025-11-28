#include <iostream>
#define MAX 5 

using namespace std;

class LinearQueue {
    int arr[MAX];
    int front, rear;
public:
    LinearQueue() {
        front = -1;
        rear = -1;
    }
    bool isFull() {
        return rear == MAX - 1;
    }
    bool isEmpty() {
        return front == -1 || front > rear;
    }
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) front = 0;
        rear++;
        arr[rear] = val;
        cout << "Inserted: " << val << "\n";
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Deleted: " << arr[front] << "\n";
        front++;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};
int main() {
    LinearQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); 
    q.display();
    return 0;
}
