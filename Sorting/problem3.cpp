#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int a[],int n){
    for(int i=1;i<n;i++){
        int curr=a[i];
        int prev=i-1;

        while(prev>=0 && curr<a[prev]){
            a[prev+1]=a[prev];
            prev--;
        }
        a[prev+1]=curr;
    }

}

int main(){
    int n;
    cout<<"Enter Array Size";
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }

     insertion_sort(arr,n);
     int smalldif=arr[1]-arr[0];


     for(int i=0;i<n-1;i++){
        if(smalldif>(arr[i+1]-arr[i])){
            smalldif=arr[i+1]-arr[i];
        }
     }
     cout<<smalldif;


return 0;
}
