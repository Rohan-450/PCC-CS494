#include<iostream>
using namespace std;

int queue[100],front=-1,rear=-1;
void enqueue(int x){
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        cout<<"Queue is empty";
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        front++;
    }
}
void peek(){
    if(front==-1 && rear==-1){
        cout<<"Queue is empty";
    }
    else{
        cout<<queue[front];
    }
}
void isempty(){
    if(front==-1 && rear==-1){
        cout<<"Queue is empty";
    }
    else{
        cout<<"Queue is not empty";
    }
}

void bfs(int graph[10][10],int n,int start){
    int visited[10]={0};
    visited[start]=1;
    enqueue(start);
    while(front!=-1 && rear!=-1){
        int x=queue[front];
        cout<<x<<" ";
        dequeue();
        for(int i=1;i<=n;i++){
            if(graph[x][i]==1 && visited[i]==0){
                visited[i]=1;
                enqueue(i);
            }
        }
    }
}
int main(){
    int graph[10][10],n,start;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter the adjacency matrix: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    cout<<"Enter the starting vertex: ";
    cin>>start;
    bfs(graph,n,start);
    return 0;
}