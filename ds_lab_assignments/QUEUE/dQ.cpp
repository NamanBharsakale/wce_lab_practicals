#include <iostream>
#define MAX 5
using namespace std;

class Deque {
    int arr[MAX];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int val) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1;
        } else {
            front = front - 1;
        }
        arr[front] = val;
        cout << "Inserted at front: " << val << "\n";
    }

    void insertRear(int val) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear = rear + 1;
        }
        arr[rear] = val;
        cout << "Inserted at rear: " << val << "\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        cout << "Deleted from front: " << arr[front] << "\n";
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front = front + 1;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        cout << "Deleted from rear: " << arr[rear] << "\n";
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1;
        } else {
            rear = rear - 1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        cout << "Deque elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << "\n";
    }
};

int main() {
    Deque dq;
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.display();
    dq.deleteFront();
    dq.display();
    dq.deleteRear();
    dq.display();
    dq.insertFront(15);
    dq.display();
    return 0;
}
