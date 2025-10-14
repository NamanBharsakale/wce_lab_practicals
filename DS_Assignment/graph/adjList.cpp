#include <iostream>
#include <vector>

using  namespace std;

int main(){
    cout<<"Enter vertices and edges: ";
    int vertices,edges;
    cin>>vertices>>edges;

    vector<int> AdjList[vertices];
    int u,v;
    cout<<"Enter (u,v): "<<endl;
    for(int i =0; i< edges;i++){
        cin>>u>>v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    for(int i = 0;i<vertices;i++){
        cout<<i<<"-> ";
        for(int j=0;j<AdjList[i].size();j++){
            cout<<AdjList[i][j]<<" ";
        }
        cout<<endl;
    }
}