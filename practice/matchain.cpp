#include<iostream>
using namespace std;

int graph[10][10],kv[10][10],p[10],n;
void initialise(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>j){
                kv[i][j]=0;
                graph[i][j]=0;
            }
        }
    }
}
void matmul(){
    int i,j,l,k;
    initialise();
    for(l=2;l<=n;l++){
        for(i=1;i<=n-l+1;i++){
            j=i+l-1;
            graph[i][j]=INT_MAX;
            for(k=i;k<=j;k++){
                if(graph[i][j]>graph[i][k]+graph[k+1][j]+(p[i-1]*p[k]*p[j])){
                    graph[i][j]=graph[i][k]+graph[k+1][j]+(p[i-1]*p[k]*p[j]);
                    kv[i][j]=k;
                }
            }
        }
    }
}
void printgraph(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
void printk(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<kv[i][j]<<" ";
        }
        cout<<endl;
    }
}
void parenthesis(int s[10][10],int i,int j){
    if(i==j){
        cout<<"A"<<i;
    }
    else{
        cout<<"(";
        parenthesis(s,i,s[i][j]);
        parenthesis(s,s[i][j]+1,j);
        cout<<")";
    }
}
int main(){
    cout<<"Enter number of matrices:"<<endl;
    cin>>n;
    cout<<"Enter dimensions:"<<endl;
    for(int i=0;i<=n;i++)
        cin>>p[i];
    matmul();
    cout<<endl;
    printgraph();
    cout<<endl;
    printk();
    cout<<endl;
    cout<<"Minimum number of multiplications:"<<graph[1][n]<<endl;
    cout<<"Optimal Parenthesization is:"<<endl;
    parenthesis(kv,1,n);
}