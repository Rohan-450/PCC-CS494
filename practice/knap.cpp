#include<iostream>
#include<algorithm>
using namespace std;

struct Item{
    int value;
    int weight;
};
static bool compare(Item i1,Item i2){
    return (i1.value/i1.weight)>(i2.value/i2.weight);
}
double knap(Item arr[],int n,int w){
    sort(arr,arr+n,compare);
    double totalvalue=0.0;
    for(int i=0;i<n;i++){
        if(arr[i].weight<w){
            w-=arr[i].weight;
            totalvalue+=arr[i].value;
        }
        else{
            totalvalue+=arr[i].value*((double)w/arr[i].weight);
        }
    }
    return totalvalue;
}
int main(){
    int n=3;
    int w=50;
    Item arr[]={{60,10},{100,20},{120,30}};
    cout<<"Maximum value we can obtain = "<<knap(arr,n,w);
    return 0;
}
