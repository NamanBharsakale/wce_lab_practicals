#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool detect(int src,vector<int> AdjList[],int visited[]){
    queue<pair<int,int>> q;
    q.push({src,-1});
    visited[src] = 1;

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(int i = 0 ; i < AdjList[node].size(); i++){
            int n = AdjList[node][i];
            if(!visited[n]){
                q.push({n,node});
                visited[n] = 1;
            }
            else if(parent != n){
                return true;
            }
        }
    }
    return false;


}

bool isCycle(int V, vector<int> AdjList[]){
    int visited[V] = {0};

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            if(detect(i,AdjList,visited)) return true;
        }
    }
    return false;
}
int main(){
    int vertex,edges;
    cout<<"Enter no. vertex and edgs: ";
    cin>>vertex>>edges;

    vector<int> AdjList[vertex];

    cout<<"Enter (v1,v2): "<<endl;

    for(int i = 0; i <edges; i++){
        int v1,v2;
        cin>>v1>>v2;
        AdjList[v1].push_back(v2);
        AdjList[v2].push_back(v1);
    }

    cout<<"Adjacency list: "<<endl;
    for(int i = 0; i < vertex; i++){
        cout<<i<<" : ";
        for(int j = 0 ; j < AdjList[i].size();j++){
            cout<<" -> "<<AdjList[i][j];
        }
        cout<<endl;
    }

    if(isCycle(vertex,AdjList)){
        cout<<"It is a cyclic graph.";
    }
    else{
        cout<<"It is not a cyclic graph.";
    }

    return 0;
}