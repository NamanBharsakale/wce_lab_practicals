#include <iostream>
using namespace std;

#define V 5

class Queue{
    public:
    int arr[V];
    int front,rear;
    public:
    Queue(){
        front = -1;
        rear = -1;
    }

    bool isFull(){
        return (rear == V - 1);
    }

    bool isEmpty(){
        return (front == -1);
    }

    

    void push(int data){
        if(isFull()){
            cout<<"Queue is full..";
            return;
        }
        if(front == -1 && rear == -1){
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
        if(isEmpty()){
            cout<<"Queue is empty..";
            return -1;
        }
        int node = arr[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front  = front + 1;
        }
        return node;
    }
};

void bfs(int G[V][V], int start,int Visited[V]){
    Queue q;
    Visited[start] = 1;
    q.push(start);

    while(!q.isEmpty()){
        int u = q.pop();
        cout<<" "<<u;
        for(int v =0 ; v <V;v++){
            if(!Visited[v] == 1 && G[u][v] == 1){
                Visited[v] = 1;
                q.push(v);
            }
        }
    }
}

void BFStraversal(int G[V][V]){
    int Visited[V] = {0};

    for(int i = 0; i< V; i++){
        if(!Visited[i]){
            bfs(G,i,Visited);
        }
    }
}
int main(){
    int G[V][V] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0}
    };

    cout<<"BFS Traversal : "<<endl;
    BFStraversal(G);

    return 0;
}