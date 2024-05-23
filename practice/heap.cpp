#include<iostream>
using namespace std;
void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[largest]<arr[left])
        largest=left;
    if(right<n && arr[largest]<arr[right])
        largest=right;
    if(largest!=i){
        swap(arr,i,largest);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n){
    int t=n;
    while(t--){
        swap(arr,0,n-1);
        n--;
        heapify(arr,n,0);
    }
}
int main(){
    int arr[10],n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    heapSort(arr,n);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}