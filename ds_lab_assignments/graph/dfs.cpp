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

void dfs(vector<int>AdjList[],vector<bool>& visited, int start){
    Stack s;
    s.push(start);
    
    while(!s.isEmpty()){
        int n = s.pop();
        
        if(!visited[n]){
            visited[n] = true;
            cout<<" "<<n;
            for(int i = 0; i < AdjList[n].size(); i++){
                int neighbour = AdjList[n][i];
                if(!visited[neighbour]){
                    s.push(neighbour);
                }
            }
        }
        }
}

int main(){
    int vertex,edges;
    cout<<"Enter the number of vertex and edges: ";
    cin>>vertex>>edges;

    vector<int> AdjList[vertex];

    cout<<"Enter the vertexes(v1,v2): "<<endl;
    for(int i = 0; i < edges;i++){
        int v1,v2;
        cin>>v1>>v2;
        AdjList[v1].push_back(v2);
        AdjList[v2].push_back(v1);
    }

    cout<<"Adjacency list: "<<endl;
    for(int i = 0; i < vertex; i++){
        cout<<i<<" : ";
        for(int j = 0; j < AdjList[i].size();j++){
            cout<<" -> "<<AdjList[i][j];
        }
        cout<<endl;
    }

    vector<bool> visited(vertex,false);
    int start;
    cout<<"Enter the starting node for dfs traversal: ";
    cin>>start;

    dfs(AdjList,visited,start);

    return 0;
}