#include<bits/stdc++.h>
using namespace std;

int main(){
    int cap = 20;
    vector<int> val = {1,2, 3 };
    vector<int> wt  = { 4, 5,6};
    int n = wt.size();

    vector<vector<int>>dp(n+1,vector<int>(cap+1,0));

    for(int i=1;i<=n;i++){
        for(int w=0;w<=cap;w++){
            dp[i][w]=dp[i-1][w];

            if(wt[i-1]<=w){
                dp[i][w] = max(dp[i][w],val[i-1]+dp[i-1][w-wt[i-1]]);
            }
        }
    }
    cout<<dp[n][cap];
    return 0;
}
