#include<iostream>
using namespace std;

int graph[10][10],parent[10],n,k;
struct edge{
    int w;
    int u;
    int v;
};
struct edge e[100];
void graphread(){
    FILE *fp;
    fp=fopen("greedy.txt","r");
    if(fp==NULL){
        cout<<"Error";
        exit(1);
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
void assignEdge(){
    k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(graph[i][j]!=999){
                e[k].w=graph[i][j];
                e[k].u=i;
                e[k].v=j;
                k++;
            }
        }
    }
}
void sort(){
    int flag;
    for(int i=0;i<k-1;i++){
        flag=0;
        for(int j=0;j<k-i-1;j++){
            if(e[j].w>e[j+1].w){
                struct edge temp=e[j];
                e[j]=e[j+1];
                e[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}
int findset(int x){
    if(parent[x]==-1){
        return x;
    }
    else{
        return findset(parent[x]);
    }
}
void unionset(int a,int b){
    parent[a]=b;
}
void kruskal(){
    int i,j;
    for(i=0;i<n;i++){
        parent[i]=-1;
    }
    sort();
    int cost=0;
    for(i=0;i<k;i++){
    int a=findset(e[i].u);
    int b=findset(e[i].v);
    if(a!=b){
        cost+=e[i].w;
        cout<<e[i].u<<"---"<<e[i].v<<" = "<<e[i].w<<endl;
        unionset(a,b);
    }
    }
    cout<<"Cost: "<<cost<<endl;
}
int main(){
    graphread();
    printgraph();
    assignEdge();
    kruskal();
    return 0;
}
