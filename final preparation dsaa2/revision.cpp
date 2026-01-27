










































// dp_revision.cpp
#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX - 1;

/* =========================================================
   0/1 KNAPSACK – RECURSIVE (BASE)
   ========================================================= */
int knapsackRec(int wt[], int val[], int n, int W){
    if(n==0 || W==0) return 0;

    if(wt[n-1] <= W){
        return max(
            val[n-1] + knapsackRec(wt, val, n-1, W-wt[n-1]),
            knapsackRec(wt, val, n-1, W)
        );
    }else{
        return knapsackRec(wt, val, n-1, W);
    }
}

/* =========================================================
   0/1 KNAPSACK – MEMOIZATION
   ========================================================= */
int memo[1005][1005];

int knapsackMemo(int wt[], int val[], int n, int W){
    if(n==0 || W==0) return 0;
    if(memo[n][W] != -1) return memo[n][W];

    if(wt[n-1] <= W){
        int inc = val[n-1] + knapsackMemo(wt, val, n-1, W-wt[n-1]);
        int exc = knapsackMemo(wt, val, n-1, W);
        return memo[n][W] = max(inc, exc);
    }else{
        return memo[n][W] = knapsackMemo(wt, val, n-1, W);
    }
}

/* =========================================================
   0/1 KNAPSACK – TABULATION
   ========================================================= */
int dpK[1005][1005];

int knapsackTab(int wt[], int val[], int n, int W){
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(i==0 || w==0) dpK[i][w]=0;
            else if(wt[i-1] <= w)
                dpK[i][w] = max(val[i-1] + dpK[i-1][w-wt[i-1]],
                                 dpK[i-1][w]);
            else
                dpK[i][w] = dpK[i-1][w];
        }
    }
    return dpK[n][W];
}

/* =========================================================
   WHICH ITEMS SELECTED (BACKTRACK)
   ========================================================= */
void printSelectedItems(int wt[], int val[], int n, int W){
    int i=n, w=W;
    cout << "Selected items:\n";
    while(i>0 && w>0){
        if(dpK[i][w] != dpK[i-1][w]){
            cout << "wt=" << wt[i-1] << " val=" << val[i-1] << "\n";
            w -= wt[i-1];
        }
        i--;
    }
}

/* =========================================================
   VARIANT 4: EXACT WEIGHT POSSIBLE? (YES/NO)
   ========================================================= */
bool poss[1005][1005];

bool exactWeightPossible(int wt[], int n, int W){
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(w==0) poss[i][w]=true;
            else if(i==0) poss[i][w]=false;
            else{
                poss[i][w] = poss[i-1][w];
                if(wt[i-1] <= w)
                    poss[i][w] = poss[i][w] || poss[i-1][w-wt[i-1]];
            }
        }
    }
    return poss[n][W];
}

/* =========================================================
   VARIANT 5: COUNT NUMBER OF WAYS (0/1)
   ========================================================= */
long long ways01[1005][1005];

long long countWays01(int wt[], int n, int W){
    for(int i=0;i<=n;i++)
        for(int w=0;w<=W;w++)
            ways01[i][w]=0;

    ways01[0][0]=1;

    for(int i=1;i<=n;i++){
        for(int w=0;w<=W;w++){
            ways01[i][w] = ways01[i-1][w];
            if(wt[i-1] <= w)
                ways01[i][w] += ways01[i-1][w-wt[i-1]];
        }
    }
    return ways01[n][W];
}

/* =========================================================
   COIN CHANGE – MINIMUM COINS (UNBOUNDED)
   ========================================================= */
int minc[1005][1005];

int minCoins(int coins[], int n, int sum){
    for(int i=0;i<=n;i++){
        for(int s=0;s<=sum;s++){
            if(s==0) minc[i][s]=0;
            else if(i==0) minc[i][s]=INF;
            else minc[i][s]=INF;
        }
    }

    for(int i=1;i<=n;i++){
        for(int s=1;s<=sum;s++){
            minc[i][s] = minc[i-1][s];
            if(coins[i-1] <= s && minc[i][s-coins[i-1]]!=INF){
                minc[i][s] = min(minc[i][s],
                                  1 + minc[i][s-coins[i-1]]);
            }
        }
    }
    return (minc[n][sum]==INF ? -1 : minc[n][sum]);
}

/* =========================================================
   COIN CHANGE – NUMBER OF WAYS (UNBOUNDED)
   ========================================================= */
long long waysCC[1005][1005];

long long coinWays(int coins[], int n, int sum){
    for(int i=0;i<=n;i++)
        for(int s=0;s<=sum;s++)
            waysCC[i][s]=0;

    waysCC[0][0]=1;

    for(int i=1;i<=n;i++){
        for(int s=0;s<=sum;s++){
            waysCC[i][s] = waysCC[i-1][s];
            if(coins[i-1] <= s)
                waysCC[i][s] += waysCC[i][s-coins[i-1]];
        }
    }
    return waysCC[n][sum];
}

/* =========================================================
   MAIN – DEMO / REVISION
   ========================================================= */
int main(){
    // ----- 0/1 Knapsack demo -----
    int wt[]  = {1,3,4,5};
    int val[] = {1,4,5,7};
    int n = 4, W = 7;

    memset(memo, -1, sizeof(memo));

    cout << "Knapsack (Recursive): " << knapsackRec(wt,val,n,W) << "\n";
    cout << "Knapsack (Memo): "      << knapsackMemo(wt,val,n,W) << "\n";
    cout << "Knapsack (Tab): "       << knapsackTab(wt,val,n,W) << "\n";
    printSelectedItems(wt,val,n,W);

    cout << "Exact weight possible? "
         << (exactWeightPossible(wt,n,W) ? "YES\n" : "NO\n");

    cout << "Number of ways (0/1): "
         << countWays01(wt,n,W) << "\n\n";

    // ----- Coin Change demo -----
    int coins[] = {1,2,3};
    int m = 3, sum = 4;

    cout << "Min coins: " << minCoins(coins,m,sum) << "\n";
    cout << "Coin change ways: " << coinWays(coins,m,sum) << "\n";

    return 0;
}
