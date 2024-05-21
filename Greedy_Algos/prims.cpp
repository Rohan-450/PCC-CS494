 #include<iostream>
 #include<stdio.h>
 #define INF 999
 using namespace std;

 int w[100][100],n;
 void readGraph(){
    FILE *fp;
    fp=fopen("graph.txt","r");
    if(fp==NULL){
        cout<<"Error";
        exit(1);
    }
    fscanf(fp,"%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fscanf(fp,"%d",&w[i][j]);
        }
    }
    fclose(fp);
 }
 void showGraph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%6d ",w[i][j]);
        }
        cout<<endl;
    }
 }
 int parent[100];
 int mstSet[100];
 int key[100];
 int minkey(){
    int min=INF;
    int minIndex=-1;
    for(int i=0;i<n;i++){
        if(mstSet[i]==0 && key[i]<min){
            min=key[i];
            minIndex=i;
        }
    }
    return minIndex;
 }
 void mstPrims(int v){
    for(int i=0;i<n;i++){
        key[i]=INF;
        mstSet[i]=0;
        parent[i]=-1;
    }
    key[v]=0;
    
    for(int i=0;i<n-1;i++){
        int u=minkey();
        mstSet[u]=1;
        for(v=0;v<n;v++){
            if(w[u][v] && mstSet[v]==0 && w[u][v]<key[v]){
                parent[v]=u;
                key[v]=w[u][v];
            }
        }
    }
}
 void print(int v){
    int cost=0;
    for(int i=0;i<n;i++){
        cost+=key[i];
        if(i!=v)
           printf("%d---%d with cost= %d\n",parent[i],i,key[i]);
    }
    cout<<"The cost is: "<<cost<<endl;
 }

int main(){
    readGraph();
    showGraph();
    mstPrims(0);
    print(0);
    return 0;
}