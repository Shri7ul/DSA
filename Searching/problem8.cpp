#include<bits/stdc++.h>
using namespace std;

int BinarySearch1st(int a[],int low,int high,int key){
    int ans=-1;
     while (low<=high){
        int mid=(high+low)/2;
        if(a[mid]==key){
            ans=mid;
            high=mid-1;
        }
        else if(a[mid]>key){
            high=mid-1;
        }
        else if(a[mid]<key){
            low=mid+1;
        }
     }
     return ans;
}
int BinarySearchlast(int a[],int low,int high,int key){
    int ans=-1;
     while (low<=high){
        int mid=(high+low)/2;
        if(a[mid]==key){
            ans= mid;
            low=mid+1;
        }
        else if(a[mid]<key){
            low=mid+1;
        }
        else if(a[mid]>key){
            high=mid-1;
        }
     }
     return ans;
}

int CountOccurrences(int arr[],int low,int high,int target) {
    int index1st=BinarySearch1st(arr,low,high,target);
    if(index1st==-1) return 0;
    int indexlast=BinarySearchlast(arr,low,high,target);
    return (indexlast-index1st)+1;
}

int main(){
    int n,target,Count;
    cout<<"Enter Array Size";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter Target";
    cin>>target;
    Count=CountOccurrences(arr,0,n-1,target);
    cout<<Count;

}


