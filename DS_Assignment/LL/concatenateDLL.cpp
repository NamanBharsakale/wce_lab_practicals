#include <iostream>
#include <cstdlib>  // for malloc and free
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to create new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at end in a given list
void insertAtEnd(Node*& head, int value) {
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
void displayList(Node* head) {
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

// Concatenate two lists
Node* concatenateLists(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* temp = head1;
    while (temp->next != NULL) temp = temp->next;

    temp->next = head2;
    head2->prev = temp;

    return head1;
}

// Main function
int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* result = NULL;
    int choice, value;

    while (true) {
        cout << "\n--- Doubly Linked List Concatenation Menu ---\n";
        cout << "1. Insert in List 1\n";
        cout << "2. Insert in List 2\n";
        cout << "3. Display List 1\n";
        cout << "4. Display List 2\n";
        cout << "5. Concatenate List 1 and List 2\n";
        cout << "6. Display Concatenated List\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(head1, value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(head2, value);
                break;
            case 3:
                displayList(head1);
                break;
            case 4:
                displayList(head2);
                break;
            case 5:
                result = concatenateLists(head1, head2);
                cout << "Lists concatenated successfully.\n";
                break;
            case 6:
                displayList(result);
                break;
            case 7:
                cout << "Exiting program.\n";
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}
