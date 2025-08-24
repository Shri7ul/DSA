#include<bits/stdc++.h>
using namespace std;

void Bubble_Sort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
                if(abs(a[j])>abs(a[j+1])){
                    swap(a[j],a[j+1]);
            }
        }
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

     Bubble_Sort(arr,n);

     for(int i=0;i<n;i++){
        cout<<arr[i];
     }

 return 0;
 }
