#include <iostream>
#include <cstdlib>  // for malloc and free
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Head pointer
Node* head = NULL;

// Function to create new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertAtEnd(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Display list
void displayList() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// Sort list using Bubble Sort
void sortList() {
    if (head == NULL) {
        cout << "List is empty, cannot sort.\n";
        return;
    }

    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    cout << "List sorted successfully.\n";
}

// Main function
int main() {
    int choice, value;

    while (true) {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at End\n";
        cout << "2. Display List\n";
        cout << "3. Sort List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 2:
                displayList();
                break;
            case 3:
                sortList();
                break;
            case 4:
                cout << "Exiting program.\n";
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}
