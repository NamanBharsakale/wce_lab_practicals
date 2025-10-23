#include <iostream>
#include <vector>
using namespace std;
#define MAX 100
class Stack{
    public:
    int top;
    int arr[MAX];
    public:
    Stack(){
        top = -1;
    }

    bool isFull(){
        return (top == MAX - 1);
    }

    bool isEmpty(){
        return (top == -1);
    }

    void push(int data){
        if(isFull()){
            cout<<"Stack is full..";
            return;
        }

        top = top + 1;
        arr[top] = data;
    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty..";
            return -1;
        }
        int data = arr[top];
        top = top - 1;
        return data;
    }
};

void dfs(vector<int> AdjList[],vector<bool>& visited,int start){
    Stack s;
    s.push(start);

    while(!s.isEmpty()){
        int node = s.pop();
        if(!visited[node]){
            cout<<" "<<node;
            visited[node] = true;

            for(int i = 0; i < AdjList[node].size(); i++){
                int neighbour = AdjList[node][i];
                if(!visited[neighbour]){
                    s.push(neighbour);
                }
            }
        }
    }
}
int main(){
    int vertex, edges;
    cout<<"Enter the number of vertexs and edges: ";
    cin>>vertex>>edges;

    vector<int> AdjList[vertex];

    cout<<"ENter the (v1,v2): "<<endl;

    for(int i = 0; i< edges; i++){
        int v1,v2;
        cin>>v1>>v2;
        AdjList[v1].push_back(v2);
        AdjList[v2].push_back(v1);
    }

    cout<<"Adjacency List : "<<endl;
    for(int i =0 ; i< vertex; i++){
        cout<<i<<" : ";
        for(int j = 0; j<AdjList[i].size(); j++){
            cout<<" -> "<<AdjList[i][j];
        }
        cout<<endl;
    }

    vector<bool> visited(vertex,false);
    int start;
    cout<<"Enter the starting vertex: ";
    cin>>start;
    dfs(AdjList,visited,start);

    return 0;
}