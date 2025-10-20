#include <iostream>
using namespace std;
#define MAX 10

class dQueue {
    int rear, front;
    int dQ[MAX];
public:
    dQueue() {
        rear = -1;
        front = -1;
    }

    void insertFront(int val) {
        if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
            cout << "Overflow..." << endl;
            return;
        }
        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1;
        } else {
            front--;
        }
        dQ[front] = val;
    }

    void insertRear(int val) {
        if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
            cout << "Overflow..." << endl;
            return;
        }
        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear++;
        }
        dQ[rear] = val;
    }

    void deleteFront() {
        if (front == -1) {
            cout << "Underflow.." << endl;
            return;
        }
        cout << "Deleted " << dQ[front] << endl;
        if (front == rear)
            front = rear = -1;
        else if (front == MAX - 1)
            front = 0;
        else
            front++;
    }

    void deleteRear() {
        if (front == -1) {
            cout << "Underflow.." << endl;
            return;
        }
        cout << "Deleted " << dQ[rear] << endl;
        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = MAX - 1;
        else
            rear--;
    }

    void display() {
        if (front == -1) {
            cout << "Underflow" << endl;
            return;
        }
        int i = front;
        while (true) {
            cout << dQ[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    dQueue d;
    d.insertFront(10);
    d.insertRear(20);
    cout << endl;
    d.deleteFront();
    cout << endl;
    d.display();
    d.insertRear(77);
    d.insertFront(89);
    cout << endl;
    d.display();
    d.deleteFront();
    d.deleteFront();
    d.deleteRear();
    cout << endl;
    d.display();

    return 0;
}
