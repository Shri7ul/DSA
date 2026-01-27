#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin >> coins[i];

    const int INF = 1e9;
    vector<int> dp(amount+1, INF);
    dp[0] = 0;

    for(int x=1; x<=amount; x++){
        for(int c: coins){
            if(c <= x) dp[x] = min(dp[x], 1 + dp[x-c]);
        }
    }

    if(dp[amount] >= INF) cout << -1 << "\n";
    else cout << dp[amount] << "\n";
}
