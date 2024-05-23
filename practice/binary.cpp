#include<iostream>
using namespace std;

void sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void binarySearch(int arr[],int l,int h,int x){
    int low=l,high=h;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x){
            cout<<"Element found at position "<<mid+1;
            exit(0);
        }
        else if(arr[mid]<x){
            binarySearch(arr,mid+1,high,x);
        }
        else{
            binarySearch(arr,low,mid-1,x); 
        }
    }
    cout<<"Element not found";
    exit(0);
}
int main(){
    int arr[10],n,x;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,n);
    cout<<"Enter the element to be searched: ";
    cin>>x;
    binarySearch(arr,0,n-1,x);
    return 0;
}