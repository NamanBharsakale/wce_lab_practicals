#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert node at end
void insertEnd(Node** head, int val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = val;
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

// Recursive function to search for key
bool recursiveSearch(Node* head, int key) {
    if (head == NULL)
        return false;
    if (head->data == key)
        return true;
    return recursiveSearch(head->next, key);
}

// Display list
void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n, val, key;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertEnd(&head, val);
    }

    cout << "Linked list: ";
    display(head);

    cout << "Enter element to search: ";
    cin >> key;

    if (recursiveSearch(head, key)) {
        cout << key << " found in the list.\n";
    } else {
        cout << key << " not found in the list.\n";
    }

    // Free allocated memory
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
