#include<bits/stdc++.h>
using namespace std;

int FindPosition(int a[],int low,int high,int target){
    int ans=high+1;
    while(low<=high){
    int mid=(low+high)/2;
    if(a[mid]>=target){
        ans=mid;
        high=mid-1;
    }
    else {
        low=mid+1;
    }
    }
  return ans;

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
    int index=FindPosition(arr,0,n-1,target);
    cout<<index;

}
