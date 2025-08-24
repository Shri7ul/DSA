/*Problem: Find the first element in an array of integers that is greater than a given target. If
no such element exists, return -1.
Example:
Input: arr = [3 5 7 2 8 10], target = 6
Output: 7*/
#include<bits/stdc++.h>
using namespace std;

int Linear_Search(int a[],int n,int key){
    for(int i=0;i<n;i++){
        if(a[i]<key){
            continue;
        }
        else return a[i];
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



