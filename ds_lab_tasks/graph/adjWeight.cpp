#include <iostream>
#include <vector>

using  namespace std;

int main(){
    cout<<"Enter vertices and edges: ";
    int vertices,edges;
    cin>>vertices>>edges;

    vector<pair<int,int>> AdjList[vertices];
    int u,v,weight;
    cout<<"Enter (u,v,weight): "<<endl;
    for(int i =0; i< edges;i++){
        cin>>u>>v>>weight;
        AdjList[u].push_back(make_pair(v,weight));
        AdjList[v].push_back(make_pair(u,weight));
    }
    cout<<"Adjacency List(u-> v w, v w,..):";
    for(int i = 0;i<vertices;i++){
        cout<<i<<"-> ";
        for(int j=0;j<AdjList[i].size();j++){
            cout<<AdjList[i][j].first<<" "<<AdjList[i][j].second<<" ,";

        }
        cout<<endl;
    }
}