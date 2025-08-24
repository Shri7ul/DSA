#include<bits/stdc++.h>
using namespace std;

int Linear_Search(int a[],int n,int key){
    for(int i=0;i<n;i++){
        if(a[i]==key) return i;
    }
    return -1;

}
int main(){
    int n,key;
    cout<<"Enter Array Size";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter key";
    cin>>key;
    int index=Linear_Search(arr,n,key);
    cout<<index;

}
