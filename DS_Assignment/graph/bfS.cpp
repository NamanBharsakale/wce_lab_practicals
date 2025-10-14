#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> bfsGraph(int V, vector<vector<int>> &adjList) {
    queue<int> q;
    vector<bool> visited(V, false);
    vector<int> ans;

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int j = 0; j < adjList[node].size(); j++) {
            int neighbor = adjList[node][j];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return ans;
}

int main() {
    cout << "Enter vertices and edges: ";
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> AdjList(vertices);
    int u, v;
    cout << "Enter (u,v): " << endl;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    for (int i = 0; i < vertices; i++) {
        cout << i << "-> ";
        for (int j = 0; j < AdjList[i].size(); j++) {
            cout << AdjList[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> res = bfsGraph(vertices, AdjList);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
