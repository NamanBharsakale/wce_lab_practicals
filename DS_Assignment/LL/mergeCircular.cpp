#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert node at end in a circular linked list
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

// Function to display a circular linked list
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Function to merge two sorted circular linked lists
Node* mergeSortedCircularLists(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* tail1 = head1;
    while (tail1->next != head1) tail1 = tail1->next;
    Node* tail2 = head2;
    while (tail2->next != head2) tail2 = tail2->next;

    // Break circularity temporarily
    tail1->next = NULL;
    tail2->next = NULL;

    // Merge two normal sorted linked lists
    Node* mergedHead = NULL;
    Node* mergedTail = NULL;

    while (head1 != NULL && head2 != NULL) {
        Node* temp = NULL;
        if (head1->data <= head2->data) {
            temp = head1;
            head1 = head1->next;
        } else {
            temp = head2;
            head2 = head2->next;
        }
        if (mergedHead == NULL) {
            mergedHead = mergedTail = temp;
            mergedTail->next = NULL;
        } else {
            mergedTail->next = temp;
            mergedTail = mergedTail->next;
            mergedTail->next = NULL;
        }
    }
    if (head1 != NULL) mergedTail->next = head1;
    if (head2 != NULL) mergedTail->next = head2;

    // Find tail of merged list to restore circularity
    mergedTail = mergedHead;
    while (mergedTail->next != NULL) {
        mergedTail = mergedTail->next;
    }
    mergedTail->next = mergedHead; // Make circular

    return mergedHead;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    int n1, n2, val;

    cout << "Enter number of nodes in first sorted circular linked list: ";
    cin >> n1;
    cout << "Enter nodes (sorted): ";
    for (int i = 0; i < n1; i++) {
        cin >> val;
        insertEnd(&head1, val);
    }

    cout << "Enter number of nodes in second sorted circular linked list: ";
    cin >> n2;
    cout << "Enter nodes (sorted): ";
    for (int i = 0; i < n2; i++) {
        cin >> val;
        insertEnd(&head2, val);
    }

    cout << "First Circular List: ";
    display(head1);
    cout << "Second Circular List: ";
    display(head2);

    Node* mergedHead = mergeSortedCircularLists(head1, head2);
    cout << "Merged Circular Sorted List: ";
    display(mergedHead);

    // Free all nodes
    if (mergedHead) {
        Node* temp = mergedHead->next;
        while (temp != mergedHead) {
            Node* nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }
        free(mergedHead);
    }

    return 0;
}
