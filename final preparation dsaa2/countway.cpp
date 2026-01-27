#include <iostream>
using namespace std;

int main() {
    int wt[] = {1, 3, 4, 5};
    int n = 4;
    int W = 7;

    long long dp[5][100]; 

    
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            dp[i][w] = 0;
        }
    }

    dp[0][0] = 1; 

    
    for(int i = 1; i <= n; i++){
        for(int w = 0; w <= W; w++){
            
            dp[i][w] = dp[i-1][w];

            
            if(wt[i-1] <= w){
                dp[i][w] += dp[i-1][w - wt[i-1]];
            }
        }
    }

    cout << "Number of ways = " << dp[n][W] << endl;
    return 0;
}
