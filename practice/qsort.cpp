#include<iostream>
using namespace std;

void print(int a[],int n){
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
  return;
}
void swap(int a[],int i,int j){
  int temp=a[i];
  a[i]=a[j];
  a[j]=temp;
  return;
}
int partition(int a[],int low,int high){
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            swap(a,i,j);
        }
        
    }
    swap(a,i+1,high);
        return i+1;
}
void quickSort(int a[],int low,int high){
    if(low<high){
        int p=partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}
int main(){
  int n;
  cout<<"Enter the number of elements: ";
  cin>>n;
  int *a=new int[n];
  cout<<"Enter the elements: ";
  for(int i=0;i<n;i++)
    cin>>a[i];
  quickSort(a,0,n-1);
  cout<<"Sorted array: ";
  print(a,n);
  return 0;
}