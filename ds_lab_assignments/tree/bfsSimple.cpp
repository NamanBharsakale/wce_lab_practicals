#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Graph as adjacency list
class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V) { 
        this->V = V; 
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Remove if directed
    }
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            cout << node << " ";
            q.pop();
            for (int neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }
};

int main() {
    Graph g(7); // Nodes: 0-A, 1-B, 2-C, 3-D, 4-E, 5-F, 6-G
    g.addEdge(0, 1); // A-B
    g.addEdge(0, 3); // A-D
    g.addEdge(1, 2); // B-C
    g.addEdge(1, 5); // B-F
    g.addEdge(3, 4); // D-E
    g.addEdge(5, 6); // F-G
    g.BFS(0); // Start BFS from node 0 (A)
    return 0;
}
