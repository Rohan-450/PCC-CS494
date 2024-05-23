#include<iostream>
using namespace std;

int stack[100],top=-1;
void push(int x){
    top++;
    stack[top]=x;
}
void pop(){
    if(top==-1){
        cout<<"Stack is empty";
    }
    else{
        top--;
    }
}
int peek(){
    if(top==-1){
        return -1;
    }
    else{
        return stack[top];
    }
}
void isempty(){
    if(top==-1){
        cout<<"Stack is empty";
    }
    else{
        cout<<"Stack is not empty";
    }
}

void bfs(int graph[10][10],int n,int start){
    int visited[10]={0};
    visited[start]=1;
    push(start);
    while(top!=-1){
        int x=peek();
        cout<<x<<" ";
        pop();
        for(int i=1;i<=n;i++){
            if(graph[x][i]==1 && visited[i]==0){
                visited[i]=1;
                push(i);
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