#include <iostream>
using namespace std;

struct Item {
    int value;
    int priority;
};

class PriorityQueue {
    Item arr[100];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int val, int pr) {
        if (size == 100) {
            cout << "Queue is full\n";
            return;
        }
        arr[size].value = val;
        arr[size].priority = pr;
        size++;
        cout << "Inserted value: " << val << " with priority: " << pr << "\n";
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int highestPriority = arr[0].priority;
        int index = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i].priority > highestPriority) {
                highestPriority = arr[i].priority;
                index = i;
            }
        }
        return index;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        int index = peek();
        cout << "Removed value: " << arr[index].value << " with priority: " << arr[index].priority << "\n";
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Priority Queue elements (value, priority):\n";
        for (int i = 0; i < size; i++) {
            cout << "(" << arr[i].value << ", " << arr[i].priority << ") ";
        }
        cout << "\n";
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(10, 2);
    pq.enqueue(20, 4);
    pq.enqueue(15, 3);
    pq.display();

    pq.dequeue();
    pq.display();

    pq.enqueue(5, 5);
    pq.display();

    pq.dequeue();
    pq.display();

    return 0;
}
