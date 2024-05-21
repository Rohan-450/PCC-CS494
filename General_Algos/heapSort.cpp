#include<iostream>
using namespace std;

void AdjustHeap(int a[],int i,int n){
  int item=a[i];
  int j=2*i;
  while(j<=n){
    if(j<n && a[j]<a[j+1])
      j=j+1;
    if(item>=a[j])
      break;
    a[j/2]=a[j];
    j=2*j;
  }
  a[j/2]=item;
}

void makeHeap(int a[],int n){
  for(int i=n/2;i>=1;i--)
    AdjustHeap(a,i,n);
}

void HeapSort(int a[],int n){
  makeHeap(a,n);
  for(int i=n;i>=2;i--){
    int temp=a[i];
    a[i]=a[1];
    a[1]=temp;
    AdjustHeap(a,1,i-1);
  }
}

int main(){
  int n;
  cout<<"Enter the number of elements: ";
  cin>>n;
  int *a=new int[n];
  cout<<"Enter the elements: ";
  for(int i=1;i<=n;i++)
    cin>>a[i];
  HeapSort(a,n);
  cout<<"Sorted array: ";
  for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";
  return 0;
}
