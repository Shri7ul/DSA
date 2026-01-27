#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>coins = {1,2,5};
    int amount = 11;

    const int INF = 1e9;

    vector<int>dp(amount+1,INF);
    dp[0]=0;

    for(int x=1;x<=amount;x++){
        for(int c : coins){
            if(c<=x){
                dp[x]=min(dp[x],1+dp[x-c]);
            }
        }
    }
    cout<<dp[amount];
    return 0;
}
