#include <iostream>
using namespace std;
#define MAX 10

class Queue {
    int front;
    int rear;
    int arr[MAX];

public:
    Queue() {
        front = rear = -1;
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Overflow.." << endl;
            return;
        }
        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else {
            rear = rear + 1;
        }
        arr[rear] = val;
    }

    void deque() {
        if (isEmpty()) {
            cout << "Underflow.." << endl;
            return;
        }
        cout << "Deleted " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = front + 1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Empty.." << endl;
            return;
        }
        cout << "Queue elements:";
        for (int i = front; i <= rear; i++) {
            cout << " " << arr[i];
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(13);
    q.display();
    q.deque();
    q.deque();
    q.enqueue(33);
    q.display();
    return 0;
}
