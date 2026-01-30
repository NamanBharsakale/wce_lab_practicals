#include <iostream>
using namespace std;

#define MAX 100

// ---------- Queue class (array implementation) ----------
class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueue(int val) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = val;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return arr[front++];
    }
};

// ---------- BFS using adjacency matrix ----------
void bfsGraph(int adj[MAX][MAX], int vertices) {
    bool visited[MAX] = {false};
    Queue q;

    cout << "\nBFS Traversal starting from vertex 0: ";

    q.enqueue(0);
    visited[0] = true;

    while (!q.isEmpty()) {
        int node = q.dequeue();
        cout << node << " ";

        for (int i = 0; i < vertices; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.enqueue(i);
            }
        }
    }
    cout << endl;
}

// ---------- Main Function ----------
int main() {
    int vertices, edges;
    cout << "Enter vertices and edges: ";
    cin >> vertices >> edges;

    int adj[MAX][MAX] = {0}; // adjacency matrix initialized to 0

    cout << "Enter (u, v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    cout << "\nAdjacency Matrix Representation:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    bfsGraph(adj, vertices);
    return 0;
}
