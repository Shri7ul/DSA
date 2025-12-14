#include<bits/stdc++.h>
using namespace std;
int Count(int arr[],int low , int high){

     if(low == high){
        return (arr[low]%2 == 0);
     }

     int mid = (low+high)/2;
     int left = Count(arr,low,mid);
     int right = Count(arr,mid+1 , high);

     return left + right;

}

int main(){
    int arr[] = {2, 5, 8, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << Count(arr, 0, n - 1);
    return 0;

}
