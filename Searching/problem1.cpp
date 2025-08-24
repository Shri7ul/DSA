/*Problem: Given an array of integers, find the first occurrence of a target integer. If the target
is not in the array, return -1.
Example:
Input: arr = [5 3 8 1 9], target = 8
Output: 2

*/

#include<bits/stdc++.h>
using namespace std;

int Linear_Search(int a[],int n,int key){
    for(int i=0;i<n;i++){
        if(a[i]==key) return i;
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
    int index=Linear_Search(arr,n,target);
    cout<<index;

}
