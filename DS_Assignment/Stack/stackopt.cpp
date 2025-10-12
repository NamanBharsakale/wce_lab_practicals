#include <iostream>
using namespace std;
#define MAX 100

class Stack{
    public:
    int top;
    int arr[MAX];

    Stack(){
        top = -1;
    }

    void push(int val){
        if(top == MAX-1){
            cout<<"Overflow..";
            return;
        }
        top = top + 1;
        arr[top] = val;
    }
    void pop(){
        if(top == -1){
            cout<<"Underflow...";
            return;
        }
        top = top - 1;
        cout<<"Popped ..";
    }

    void display(){
        for(int i = top; i> -1;i--){
            cout<<arr[i]<<" ";
        }
    }
};
int main()
{
    Stack s;
    int choice, value;

    while (true) {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display Stack" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.display();
                break;

            case 4:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}