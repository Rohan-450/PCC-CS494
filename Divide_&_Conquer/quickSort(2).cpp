#include<iostream>
using namespace std;

int partition(int arr[],int low,int high){
  int pivot=arr[low];
  int i=low-1,j=high+1;
  while(true){
    do{
      i++;
    }while(arr[i]<pivot);
    do{
      j--;
    }while(arr[j]>pivot);
    if(i>=j)
      return j;
    swap(arr[i],arr[j]);
  }
}
void quickSort(int arr[],int low,int high){
  if(low<high){
    int pi=partition(arr,low,high);
    quickSort(arr,low,pi);
    quickSort(arr,pi+1,high);
  }
}
void print(int arr[],int n){
  for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
  return;
}
int main(){
  int n;
  cout<<"Enter the number of elements: ";
  cin>>n;
  int arr[n];
  cout<<"Enter the elements: ";
  for(int i=0;i<n;i++)
    cin>>arr[i];
  quickSort(arr,0,n-1);
  cout<<"Sorted array: ";
  print(arr,n);
  return 0;
}
