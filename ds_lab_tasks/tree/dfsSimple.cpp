#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> s;
    s.push(start);
    visited[start] = true;
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        cout << char('A' + node) << " "; // Print node as letter
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    // Example graph edges (A=0, B=1, ..., G=6)
    vector<vector<int>> adj = {
        {1, 3},      // A connects to B, D
        {0, 2, 5},   // B connects to A, C, F
        {1, 4, 6},   // C connects to B, E, G
        {0, 5},      // D connects to A, F
        {2},         // E connects to C
        {1, 3},      // F connects to B, D
        {2}          // G connects to C
    };
    vector<bool> visited(7, false);
    dfs(0, adj, visited); // Start DFS from A (0)
    return 0;
}
