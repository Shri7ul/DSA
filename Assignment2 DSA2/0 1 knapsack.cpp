#include<iostream>
using namespace std;

int memo[1000][1000];
int tab[1000][1000];

int knapsack(int wt[],int p[],int n, int W){

//base case
if(n==0||W==0){ //no item  or no capacity remaining
return 0;
}

if(memo[n][W]!=-1){
    return memo[n][W];
}

else{

if(wt[n-1]<=W){
   //We can include or exlcude the item.
   int inc = knapsack(wt,p,n-1,W-wt[n-1]) + p[n-1];
   int exc = knapsack(wt,p,n-1,W);
   memo[n][W]=max(inc,exc);
   return memo[n][W];
}
else{
    int exc = knapsack(wt,p,n-1,W);
    memo[n][W]=exc;
    return memo[n][W];

}

}
}

int tab_knapsack(int wt[],int p[],int n, int W){


for(int i=0;i<=n;i++){
    for(int j=0;j<=W;j++){

      if(i==0||j==0){
        tab[i][j]=0;
      }

      else{
        if(wt[i-1]<=j){
            tab[i][j]= max( p[i-1]+tab[i-1][j-wt[i-1]] , tab[i-1][j] );
        }
        else{
             tab[i][j]=tab[i-1][j];
        }
      }


    }
}

return tab[n][W];








}

int main(){


int weight[]={1,3,4,5};
int profit[]={1,4,5,7};
int n=4;
int W=7;


for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0||j==0){
                memo[i][j]=0;
            }
            else{
               memo[i][j]=-1;
            }
        }

}
cout<<knapsack(weight,profit,n,W)<<endl;
cout<<tab_knapsack(weight,profit,n,W)<<endl;

}