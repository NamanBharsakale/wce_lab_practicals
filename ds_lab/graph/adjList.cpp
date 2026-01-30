#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    // Insert a node at the beginning
    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Display the adjacency list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

// Main Graph Program
int main() {
    int vertices, edges;
    cout << "Enter vertices and edges: ";
    cin >> vertices >> edges;

    // Array of LinkedList for adjacency representation
    LinkedList adj[100];  // assuming max 100 vertices

    cout << "Enter (u, v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);  // Add v to u’s list
        adj[v].insert(u);  // Add u to v’s list (for undirected graph)
    }

    cout << "\nAdjacency List Representation:\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";
        adj[i].display();
        cout << endl;
    }

    return 0;
}
