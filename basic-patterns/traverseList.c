#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to traverse and print the list
void traverseList(struct Node* head) {
    struct Node* PTR = head;
    while (PTR != NULL) {
        printf("%d ", PTR->data);      // Step 3: Print info
        PTR = PTR->next;               // Step 4: Move pointer
    }
    printf("\n");
}

// Example usage
int main() {
    // Manually creating 3 nodes for demo
    struct Node* head = malloc(sizeof(struct Node));
    struct Node* second = malloc(sizeof(struct Node));
    struct Node* third = malloc(sizeof(struct Node));

    head->data = 1;  head->next = second;
    second->data = 2;  second->next = third;
    third->data = 3; third->next = NULL;

    traverseList(head);

    // Free the allocated memory
    free(head); free(second); free(third);
    return 0;
}
