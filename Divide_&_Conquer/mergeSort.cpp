#include<iostream>
using namespace std;

void merge(int a[],int l,int m,int r){
  int B[100];
  int i=l,j=m+1,k=l;
  while(i<=m && j<=r){
    if(a[i]<a[j])
      B[k++]=a[i++];
    else
      B[k++]=a[j++];
  }
  while(i<=m)
    B[k++]=a[i++];
  while(j<=r)
    B[k++]=a[j++];
  for(int i=l;i<=r;i++)
    a[i]=B[i];
}
void mergeSort(int a[],int l,int r){
  if(l<r){
    int m=(l+r)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);
    merge(a,l,m,r);
  }
}

int main(){
  int size;
  cout<<"Enter Size of Array:";
  cin>>size;
  int a[size];
  cout<<"Enter elements:";
  for(int i=0;i<size;i++)
    cin>>a[i];
  mergeSort(a,0,size-1);
  cout<<"Sorted Array:";
  for(int i=0;i<size;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}
