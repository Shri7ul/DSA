#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX - 1;

int main() {
    int coins[] = {1, 2, 3, 4};
    int n = 4;
    int sum = 4;

    int dp[5][100]; 

    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            if(j == 0) dp[i][j] = 0;       
            else if(i == 0) dp[i][j] = INF;
            else dp[i][j] = INF;
        }
    }

    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            
            dp[i][j] = dp[i-1][j];

            
            if(coins[i-1] <= j && dp[i][j - coins[i-1]] != INF){
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i-1]]);
            }
        }
    }

    if(dp[n][sum] == INF) cout << "Not possible\n";
    else cout << "Minimum coins = " << dp[n][sum] << endl;

    return 0;
}
