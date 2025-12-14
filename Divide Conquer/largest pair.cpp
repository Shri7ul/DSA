//Find the largest pair in a given array.

#include<bits/stdc++.h>
using namespace std;

pair<int ,int>largestPair(int arr[],int low ,int high){
    if (low == high) {
    return {arr[low], INT_MIN};
}
   if(high -low == 1){
     if( arr[low]>arr[high]){
        return {arr[low], arr[high]};
     }
     else return {arr[high], arr[low]};
   }
   int mid = (low + high)/2;

   pair<int,int>left =largestPair(arr, low, mid);
   pair<int,int>right =largestPair(arr, mid+1,high);

   int max1,max2;

   if (left.first > right.first) {
        max1 = left.first;
        max2 = max(left.second, right.first);
    } else {
        max1 = right.first;
        max2 = max(right.second, left.first);
    }

    return {max1, max2};
}
int main() {
    int arr[] = {5, 1, 9, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    pair<int , int> ans = largestPair(arr, 0, n - 1);

    cout << "Largest pair: " << ans.first << " " << ans.second;
    return 0;
}





