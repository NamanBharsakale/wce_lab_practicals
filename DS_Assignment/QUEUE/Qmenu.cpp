#include <iostream>
#define MAX 5

using namespace std;

class CircularQueue {
    int arr[MAX];
    int front, rear;

    public:
    CircularQueue(){
        front = -1;
        rear = -1;
    }

    void enqueue(int val){
        if((rear+1)%MAX == front){
            cout<<"Overflow..";
            return;
        }

        if(front == -1){
            front = 0;
            rear = 0;
        }
        else{
            rear = (rear + 1)% MAX;
        }
        arr[rear] = val;
    }

    void dequeue(){
        if(front == -1){
            cout<<"Underflow...";
            return;
        }
        cout<<"Deleted "<<arr[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front+1)%MAX;
        }
    }

    void display(){
        if(front == -1){
            cout<<"Empty..";
            return;
        }
        for(int i = front; i<= rear;i++){
            cout<<" "<<arr[i];
        }
    }

    
};

int main() {
    CircularQueue q;
    int choice, val;

    do {
        cout << "\nMenu\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
