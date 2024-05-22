#include<iostream>
using namespace std;
int counter=0;
void maxmin(int arr[],int i,int j,int &max,int &min){
    if(i==j)
        max=min=arr[j];
    else if(i+1==j){
        if(arr[i]>arr[j]){
            max=arr[i];
            min=arr[j];
        }
        else{
            max=arr[j];
            min=arr[i];
        }
        counter++;
    }
    else{
        int mid=(i+j)/2;
        int max1,min1;
        maxmin(arr,i,mid,max,min);
        maxmin(arr,mid+1,j,max1,min1);
        if(max<max1)
            max=max1;
        if(min>min1)
            min=min1;
        counter+=2;
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
    int max=arr[0];
    int min=arr[0];
    maxmin(arr,0,n-1,max,min);
    cout<<"Maximum Element:"<<max<<endl;
    cout<<"Minimum Element:"<<min<<endl;
    cout<<"Number of Comparisons:"<<counter<<endl;
    return 0;
}