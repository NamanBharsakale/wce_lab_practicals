#include <iostream>
#include <vector>
using namespace std;

int main(){
    int vertex,edges;
    cout<<"Enter no. vertex and edgs: ";
    cin>>vertex>>edges;

    vetor<int> AdjList[vertex];

    cout<<"Enter (v1,v2): "<<endl;

    for(int i = 0; i <edges; i++){
        cin>>v1>>v2;
        AdjList[v1].push_back(v2);
        AdjList[v2].push_back(v1);
    }

    cout<<"Adjacency list: "<<endl;
    for(int i = 0; i < vertex; i++){
        cout<<i>>" : ";
        for(int j = 0 ; j < AdjList[i].size();j++){
            cout<<" -> "<<AdjList[i][j];
        }
        cout<<endl;
    }
}