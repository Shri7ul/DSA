#include <iostream>
using namespace std;

int main() {
    int coins[] = {1, 2, 3};
    int n = 3;
    int sum = 4;

    long long dp[5][100];

    // Base
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            dp[i][j] = 0;
        }
    }

    // 1 way to make sum 0: choose nothing
    dp[0][0] = 1;

    // Fill
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            // skip coin
            dp[i][j] = dp[i-1][j];

            // take coin (unbounded -> same row i)
            if(coins[i-1] <= j){
                dp[i][j] += dp[i][j - coins[i-1]];
            }
        }
    }

    cout << "Number of ways = " << dp[n][sum] << endl;
    return 0;
}
