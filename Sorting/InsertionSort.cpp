#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        int curr=a[i];
        int prev=i-1;

        while(prev>=0 && a[prev]>curr){
            a[prev+1]=a[prev];
            prev--;
        }
        a[prev+1]=curr;
    }
}
 int main(){
     int n,key;
     cout<<"Enter Array Size";
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }

     InsertionSort(arr,n);
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
     }

 return 0;
 }
