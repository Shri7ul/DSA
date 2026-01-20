#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int n = 4;
    int P = 9;   


    int dp[5][20];


    for(int i = 0; i <= n; i++){
        for(int p = 0; p <= P; p++){
            if(p == 0)
                dp[i][p] = 0;      
            else
                dp[i][p] = INF;  
        }
    }

    // DP filling
    for(int i = 1; i <= n; i++){
        for(int p = 1; p <= P; p++){

            dp[i][p] = dp[i-1][p];


            if(val[i-1] <= p){
                dp[i][p] = min(
                    dp[i][p],
                    wt[i-1] + dp[i-1][p - val[i-1]]
                );
            }
        }
    }

    if(dp[n][P] >= INF)
        cout << "Not possible\n";
    else
        cout << "Minimum weight = " << dp[n][P] << endl;

    return 0;
}
