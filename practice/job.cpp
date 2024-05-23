#include<iostream>
#include<algorithm>
using namespace std;

struct job{
    int id;
    int deadline;
    int profit;
};

static bool compare(job j1,job j2){
    return (j1.profit>j2.profit);
}
int maxDead(job arr[],int n){
    int max=arr[0].deadline;
    for(int i=1;i<n;i++){
        if(arr[i].deadline>max){
            max=arr[i].deadline;
        }
    }
    return max;
}
void jobS(job arr[],int n){
    sort(arr,arr+n,compare);
    int m=maxDead(arr,n);
    int result[n];
    int slot[n];
    for(int i=0;i<n;i++){
        slot[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=m;j>=0;j--){
            if(slot[j]==0){
                result[j]=i;
                slot[j]=1;
                break;
            }
        }
    }
    cout<<"The sequence of jobs is: ";
    for(int i=0;i<n;i++){
        if(slot[i]){
            cout<<arr[result[i]].id<<" ";
        }
    }
    cout<<endl;
}
int main(){
    int n=5;
    job arr[]={{1,2,100},{2,1,19},{3,2,27},{4,1,25},{5,3,15}};
    jobS(arr,n);
    return 0;
}