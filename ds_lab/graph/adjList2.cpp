#include <iostream>
#include <vector>
using namespace std;

int main(){

    int vertex,edges;
    cout<<"Enter the vertices and edges: ";
    cin>>vertex>>edges;

    vector<int> AdjList[vertex];
    cout<<"Enter the (v1,v2): "<<endl;

    for(int i = 0 ; i < edges; i++){
        int v1,v2;
        cin>>v1>>v2;
        AdjList[v1].push_back(v2);
        AdjList[v2].push_back(v1);
    }

    cout<<"Adjacency List: "<<endl;
    for(int i = 0; i< vertex;i++){
        cout<<i<<" : ";
        for(int j = 0; j < AdjList[i].size(); j++){
            cout<<" -> "<<AdjList[i][j];
        }
        cout<<endl;
    }

    return 0;
}