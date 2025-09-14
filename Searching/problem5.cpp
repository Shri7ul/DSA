#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int a[],int low,int high,int key){
     while (low<=high){
        int mid=(high+low)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]>key){
            low=mid;
        }
        else if(a[mid]<key){
            high=mid;
        }
     }
     return -1;
}


int main(){
    int n,target;
    cout<<"Enter Array Size";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter Target";
    cin>>target;
    int index=BinarySearch(arr,0,n-1,target);
    cout<<index;

}
