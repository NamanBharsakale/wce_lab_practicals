#include <iostream>
#include <vector>
using namespace std;

int main(){
    cout << "Enter number vertices and edges: ";
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<int>> Adj(vertex, vector<int>(vertex, 0));

    cout << "Enter the (u v weight): " << endl;
    int u, v, weight;
    for(int i = 0; i < edges; i++){
        cin >> u >> v >> weight;
        Adj[u][v] = weight;
        Adj[v][u] = weight; 
    }

    cout << "Adjacency Matrix:" << endl;
    for(int i = 0; i < vertex; i++){ 
        for(int j = 0; j < vertex; j++){
            cout << Adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
