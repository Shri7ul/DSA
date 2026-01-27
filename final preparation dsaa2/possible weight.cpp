#include <iostream>
using namespace std;

int main() {
    int wt[] = {1, 3, 4, 5};
    int n = 4;
    int W = 7;

    bool dp[5][100]; 

    
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(w == 0) dp[i][w] = true;      
            else if(i == 0) dp[i][w] = false; 
            else dp[i][w] = false;
        }
    }

   
    for(int i = 1; i <= n; i++){
        for(int w = 1; w <= W; w++){
           
            dp[i][w] = dp[i-1][w];

           
            if(wt[i-1] <= w){
                dp[i][w] = dp[i][w] || dp[i-1][w - wt[i-1]];
            }
        }
    }

    if(dp[n][W]) cout << "YES, exact weight possible\n";
    else         cout << "NO, exact weight not possible\n";

    return 0;
}
