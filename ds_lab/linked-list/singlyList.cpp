#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at beginning
void insertBeginning(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Insert at end
void insertEnd(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Insert at middle position (after pos nodes, pos starts at 0)
void insertMiddle(Node** head, int value, int pos) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (pos == 0 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    for (int i = 0; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Position out of range.\n";
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteBeginning(Node** head) {
    if (*head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete from end
void deleteEnd(Node** head) {
    if (*head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

// Delete from middle position (pos starts at 0)
void deleteMiddle(Node** head, int pos) {
    if (*head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = *head;
    if (pos == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of range.\n";
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

// Display list
void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    Node* head = NULL;
    int choice, value, pos;
    while (1) {
        cout << "\nMenu:\n"
             << "1. Insert at Beginning\n"
             << "2. Insert at End\n"
             << "3. Insert at Position\n"
             << "4. Delete from Beginning\n"
             << "5. Delete from End\n"
             << "6. Delete from Position\n"
             << "7. Display\n"
             << "8. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertBeginning(&head, value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertEnd(&head, value);
                break;
            case 3:
                cout << "Enter value and position (0-based): ";
                cin >> value >> pos;
                insertMiddle(&head, value, pos);
                break;
            case 4:
                deleteBeginning(&head);
                break;
            case 5:
                deleteEnd(&head);
                break;
            case 6:
                cout << "Enter position (0-based): ";
                cin >> pos;
                deleteMiddle(&head, pos);
                break;
            case 7:
                display(head);
                break;
            case 8:
                // Free all nodes before exit
                while (head != NULL) {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
