#include<iostream>
using namespace std;
int n,graph[10][10];
void readgraph(){
    FILE *fp;
    fp=fopen("greedy.txt","r");
    if(fp==NULL){
        cout<<"Error";
        exit(0);
    }
    fscanf(fp,"%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fscanf(fp,"%d",&graph[i][j]);
        }
    }
    fclose(fp);
}
void printgraph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
int parent[100];
int key[100];
int mstSet[100];
int minKey(){
    int min=999;
    int minIndex=-1;
    for(int i=0;i<n;i++){
        if(mstSet[i]==0 && key[i]<min){
            min=key[i];
            minIndex=i;
        }
    }
    return minIndex;
}
void djikstra(int v){
    for(int i=0;i<n;i++){
        parent[i]=-1;
        key[i]=999;
        mstSet[i]=0;
    }
    key[v]=0;
    for(int i=0;i<n-1;i++){
        int u=minKey();
        mstSet[u]=1;
        for(v=0;v<n;v++){
            if(graph[u][v] && mstSet[v]==0 && key[u]+graph[u][v]<key[v]){
                key[v]=key[u]+graph[u][v];
                parent[v]=u;
            }
        }
    }
}
void showpath(int w){
    if(parent[w]==-1){
        cout<<"S";
    }
    else{
        showpath(parent[w]);
        cout<<"--> "<<w;
    }
}
void print(int v){
    for(int i=1;i<n;i++){
        if(i!=v){
            cout<<"S"<<"---"<<i<<" = "<<key[i]<<endl;
        }
        cout<<"Path: ";
        showpath(i);
        cout<<endl;
        cout<<endl;
    }
}
int main(){
    readgraph();
    printgraph();
    djikstra(0);
    print(0);
    return 0;
}