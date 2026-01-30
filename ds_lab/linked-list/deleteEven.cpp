#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert node at end 
void insertEnd(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode; 
        return;
    }
    Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

// Function to display circular linked list
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Function to delete node after 'prev' 
void deleteNextNode(Node** head, Node* prev) {
    if (*head == NULL) return;

    Node* del = prev->next;
    if (del == *head) {
        if ((*head)->next == *head) {
            free(del);
            *head = NULL;
            return;
        }
        *head = del->next;
    }
    prev->next = del->next;
    free(del);
}

// Function to delete nodes at even positions
void deleteEvenPositions(Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == *head) return; // only one node

    Node* prev = *head;
    int pos = 1;

    while (prev->next != *head) {
        if (pos % 2 == 1) {
            deleteNextNode(head, prev);
            // after deletion prev->next updates, do not move prev
        } else {
            prev = prev->next;
        }
        pos++;
    }
    // Handle last node if necessary based on position count
    if (pos % 2 == 1 && prev->next == *head) {
        deleteNextNode(head, prev);
    }
}

int main() {
    Node* head = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertEnd(&head, value);
    }

    cout << "Original circular linked list: ";
    display(head);

    deleteEvenPositions(&head);

    cout << "After deleting nodes at even positions: ";
    display(head);

    // Free remaining nodes
    while (head != NULL) {
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            Node* del = head;
            head = head->next;
            free(del);
        }
    }

    return 0;
}
