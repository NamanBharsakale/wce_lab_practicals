#include <iostream>
using namespace std;

int main(){
    int vertex,edges;
    cout<<"Enter the vertices and edges: ";
    cin>>vertex>>edges;

    int adjMat[vertex+1][vertex+1];
    for(int i  =1; i<= vertex; i++){
        for(int j = 1; j<= vertex;j++){
            adjMat[i][j] = 0;
        }
    }

    cout<<"Enter the (v1,v2,weight): "<<endl;
    for(int i = 0; i<edges;i++){
        int v1,v2,weight;
        cin>>v1>>v2>>weight;
        adjMat[v1][v2] = weight;
        adjMat[v2][v1] = weight;
    }

    cout<<"Adjacency Matrix: "<<endl;
    for(int i  =1; i<= vertex; i++){
        for(int j = 1; j<= vertex;j++){
            cout<<" "<<adjMat[i][j];
        }
        cout<<endl;
    }
    return 0;
}