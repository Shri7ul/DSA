#include<bits/stdc++.h>
using namespace std;

int BinarySearch1st(int a[],int low,int high,int key){
     while (low<=high){
        int mid=(high+low)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]>key){
            high=mid;
        }
        else if(a[mid]<key){
            low=mid;
        }
     }
     return -1;
}
int BinarySearchlast(int a[],int low,int high,int key){
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
    int index1st=BinarySearch1st(arr,0,n-1,target);
    int indexlast=BinarySearchlast(arr,0,n-1,target);
    cout<<index1st<<","<<index1st;

}

