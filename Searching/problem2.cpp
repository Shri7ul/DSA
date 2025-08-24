/*Problem: Given an array, find all the indices where a target integer appears. Return an array
of indices. If the target does not appear, return an empty array.
Example:
Input: arr = [4 2 3 2 4 2], target = 2
Output: [1, 3, 5]
*/
#include<bits/stdc++.h>
using namespace std;


int Linear_Search(int arr[],int n,int key,int indices[]){
    int Count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
           indices[Count]=i;
           Count++;
        }
    }
    return Count;
}
int main(){
    int n,target;
    cout<<"Enter Array Size";
    cin>>n;
    int arr[n];
    int indices[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter Target";
    cin>>target;
    int Count =Linear_Search(arr,n,target,indices);
    if(Count==0){
        cout<<"Doesn't Exist";
    }
    else{
            for(int i=0;i<Count;i++){
        cout<<indices[i]<<" ";
    }

    }



}
