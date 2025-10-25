#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topologicalSortUtil(vector<int> AdjList[],vector<bool>& visited,int node,stack<int>& finishstack){
    visited[node] = true;

    for(int i = 0; i < AdjList[node].size(); i++){
        int n = AdjList[node][i];
        if(!visited[n]){
            topologicalSortUtil(AdjList,visited,n,finishstack);
        }
    }

    finishstack.push(node);
}

void topologicalSort(vector<int> AdjList[],int vertex ){
    vector<bool> visited(vertex,false);

    stack<int> finishstack;

    for(int i = 0; i< vertex;i++){
        if(!visited[i]){
            topologicalSortUtil(AdjList,visited,i,finishstack);
        }
    }

    cout<<"Topological Sort: ";
    while(!finishstack.empty()){
        cout<<" "<<finishstack.top();
        finishstack.pop();
    }

    cout<<endl;
}
int main(){

    int vertex,edges;
    cout<<"How many vertices and edges are there: ";

    cin>>vertex>>edges;

    vector<int> AdjList[vertex];
    cout<<"Enter the edges (v1 -> v2) : "<<endl;
    for(int  i = 0; i < edges; i++){
        int v1,v2;
        cin>>v1>>v2;
        AdjList[v1].push_back(v2);
    }

    cout<<"Adjacency List: "<<endl;
    for(int  i =0 ; i<vertex; i++){
        cout<<i<<" : ";
        for(int j = 0; j < AdjList[i].size(); j++){
            cout<<" -> "<<AdjList[i][j];
        }
        cout<<endl;
    }

    topologicalSort(AdjList,vertex);


}