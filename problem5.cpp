#include<bits/stdc++.h>
using namespace std;

void selection_sort(string a[],int n){
    for(int i=0;i<n-1;i++){
           int smallest=i;
        for(int j=i+1;j<n;j++){
            if(a[smallest].length()>a[j].length()){
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

    string arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
     }

    selection_sort(arr,n);

     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
     }

return 0;
}

