#include <iostream>
#include <cstdlib>  
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

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

// Insert at given position (1-based index)
void insertAtPosition(int value, int pos) {
    if (pos <= 1) {
        insertAtBeginning(value);
        return;
    }

    Node* newNode = createNode(value);
    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        insertAtEnd(value);
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(temp);
}

void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    if (temp->prev != NULL) temp->prev->next = NULL;
    else head = NULL;  
    free(temp);
}

void deleteFromPosition(int pos) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (pos <= 1) {
        deleteFromBeginning();
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position.\n";
        return;
    }

    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    else head = temp->next; 
    free(temp);
}

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

int main() {
    int choice, value, pos;

    while (true) {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                insertAtPosition(value, pos);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deleteFromPosition(pos);
                break;
            case 7:
                displayList();
                break;
            case 8:
                cout << "Exiting program.\n";
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}

