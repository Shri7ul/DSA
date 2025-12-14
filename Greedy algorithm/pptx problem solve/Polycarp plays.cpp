#include<bits/stdc++.h>
using namespace std;

int main(){
   int a,b;
   cin>>a>>b;
   int tools=0;

   while(true){
    if(a>=2 && b>=1 && a>=b){
        a -= 2;
        b -= 1;
        tools++;
    }
    else if(b>=2 && a>=1 && b>=a){
       b -= 2;
       a -= 1;
        tools++;
   }
   else break;
   }

   cout<<tools;
   return 0;
}
