#include<iostream>
using namespace std;
int graph[10][10],parent[10],mstSet[10],key[10],n;
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
int minkey(){
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
void prims(int v){
    for(int i=0;i<n;i++){
        key[i]=999;
        mstSet[i]=0;
        parent[i]=-1;
    }
    key[v]=0;
    for(int i=0;i<n-1;i++){
        int u=minkey();
        mstSet[u]=1;
        for(v=0;v<n;v++){
            if(graph[u][v] && mstSet[v]==0 && graph[u][v]<key[v]){
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
}
void print(int v){
    int cost=0;
    for(int i=0;i<n;i++){
        cost+=key[i];
        if(i!=v){
        cout<<parent[i]<<"--"<<i<<"="<<key[i]<<endl;
        }
    }
    cout<<"Cost="<<cost;
}
int main(){
    readgraph();
    printgraph();
    prims(0);
    print(0);
    return 0;
}