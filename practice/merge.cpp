#include<iostream>
using namespace std;

void merge(int arr[],int l,int m,int r){
    int B[100];
    int i=l;
    int j=m+1;
    int k=l;
    while(i<=m && j<=r){
        if(arr[i]<arr[j]){
            B[k++]=arr[i++];
        }
        else{
            B[k++]=arr[j++];
        }
    }
    while(i<=m){
        B[k++]=arr[i++];
    }
    while(j<=r){
        B[k++]=arr[j++];
    }
    for(int i=0;i<=r;i++){
        arr[i]=B[i];
    }
}
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements:"<<endl;
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}