 #include<bits/stdc++.h>
 using namespace std;

 void SelectionSort(int a[],int n){

    for(int i=0;i<n-1;i++){
      int small=i;
       for(int j=i+1;j<n;j++){
         if(a[small]>a[j]){
            small=j;
         }
       }
       swap(a[i],a[small]);

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

     SelectionSort(arr,n);
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
     }

 return 0;
 }

