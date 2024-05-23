#include<iostream>
using namespace std;
int graph[10][10],n,key[10],parent[10];
void readgraph(){
    FILE *fp;
    fp=fopen("bell.txt","r");
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
void bellman(int s){
    for(int i=0;i<n;i++){
        key[i]=999;
        parent[i]=-1;
    }
    key[s]=0;
    for(int i=0;i<n-1;i++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]!=999){
                    if(key[i]+graph[i][j]<key[j]){
                        key[j]=key[i]+graph[i][j];
                        parent[j]=i;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]!=999){
                if(key[i]+graph[i][j]<key[j]){
                    cout<<"Negative cycle detected"<<endl;
                    return;
                }
            }
        }
    }
}
void printpath(int w){
    if(parent[w]==-1){
        cout<<"S";
    }
    else{
        printpath(parent[w]);
        cout<<"->"<<w;
    }
}
void print(){
    for(int i=1;i<n;i++){
        cout<<"S to "<<i<<" = "<<key[i]<<endl;
        printpath(i);
        cout<<endl;
    }
}
int main(){
    int s;
    readgraph();
    printgraph();
    cout<<"Enter source vertex:";
    cin>>s;
    bellman(s);
    print();
    return 0;
}