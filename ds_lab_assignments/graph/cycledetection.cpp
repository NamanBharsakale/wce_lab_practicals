#include <iostream>
#include <vector>
using namespace std;
#define MAX  10
class Queue{
    public:
    int rear,front;
    int arr[MAX];
    public:
    Queue(){
        front = -1;
        rear = -1;
    }

    void push(int data){
        if(rear == MAX -1){
            cout<<"Queue is full";
            return;
        }
        if(front = -1 && rear == -1){
            front = 0;
            rear = 0;
        }
        else{
            rear = rear + 1;
        }
        arr[rear] = data;
        return;
    }

    int pop(){
        if(front == -1){
            cout<<"Queu is empty";
            return -1;
        }

        int data = arr[front];
        if(rear == front){
            front = -1;
            rear = -1;
        }
        else{
            front = front + 1;
        }

        return data;
    }

    bool isEmpty(){
        return (front == -1);
    }
};
void bfsTraversal(vector<int> AdjList[],int start, vector<bool> visited){
    Queue q;
    q.push(start);
    visited[start] = true;

    while(!q.isEmpty()){
        int n = q.pop();
        cout<<" "<<n;
        

        for(int i = 0; i < AdjList[n].size(); i++){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}



void bfs(vector<int> AdjList[],int vertex){
    vector<bool> visited(vertex,false);

    for(int i = 0; i < vertex; i++){
        bfsTraversal(AdjList,i,visited);
    }
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

    bfs(AdjList,vertex);
}