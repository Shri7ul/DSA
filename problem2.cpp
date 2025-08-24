#include<bits/stdc++.h>
using namespace std;

void selection_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
           int smallest=i;
        for(int j=i+1;j<n;j++){
            if(a[smallest]>a[j]){
                smallest=j;
            }

        }
         swap(a[i],a[smallest]);
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

     selection_sort(arr,n);

     if(n%2!=0){
        cout<<arr[n/2];
     }
     else{
        int median=(arr[n/2]+arr[((n/2)-1)])/2;
        cout<<median;
     }

return 0;
}
