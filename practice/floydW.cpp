#include<iostream>
using namespace std;
int graph[10][10],P[10][10],n,D[10][10];
void readgraph(){
    FILE *fp;
    fp=fopen("flo.txt","r");
    if(fp==NULL){
        cout<<"Error";
        exit(0);
    }
    fscanf(fp,"%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            fscanf(fp,"%d",&graph[i][j]);
        }
    }
    fclose(fp);
}
void printgraph(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
void floyd(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            D[i][j]=graph[i][j];
            if(graph[i][j]==999 || graph[i][j]==0)
                P[i][j]=0;
            else
                P[i][j]=i;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(D[i][j]>D[i][k]+D[k][j]){
                    D[i][j]=D[i][k]+D[k][j];
                    P[i][j]=P[k][j];
                }
            }
        }
    }
}
void printD(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<D[i][j]<<" ";
        }
        cout<<endl;
    }
}
void printP(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<P[i][j]<<" ";
        }
        cout<<endl;
    }
}
void printpath(int i,int j){
    if(i==j){
        cout<<i<<" ";
    }
    else if(P[i][j]==0){
        cout<<"No path";
    } 
    else{
        printpath(i,P[i][j]);
        cout<<"-> "<<j<<" ";
    }
}
void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<"Shortest path from "<<i<<" to "<<j<<" is: "<<D[i][j]<<endl;
            printpath(i,j);
            cout<<endl;
        }
    }
}
int main(){
    readgraph();
    printgraph();
    floyd();
    cout<<endl;
    printD();
    cout<<endl;
    printP();
    cout<<endl;
    print();
    return 0;
}