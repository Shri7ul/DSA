//base (0/1 knapsack recursion)
int knapsack(int wt[], int val[], int n, int W){
    if(n==0 || W==0) return 0;

    if(wt[n-1] <= W){
        return max(
            val[n-1] + knapsack(wt, val, n-1, W-wt[n-1]),
            knapsack(wt, val, n-1, W)
        );
    }else{
        return knapsack(wt, val, n-1, W);
    }
}
// 0/1 KNAPSACK — Memoization (Top-Down)
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

// init memo (call before using)
for(int i=0;i<=n;i++)
  for(int w=0;w<=W;w++)
    memo[i][w] = (i==0 || w==0) ? 0 : -1;



// 0/1 KNAPSACK — Tabulation (Bottom-Up)

int dp[1005][1005];

for(int i=0;i<=n;i++){
  for(int w=0;w<=W;w++){
    if(i==0 || w==0) dp[i][w]=0;
    else if(wt[i-1] <= w)
      dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
    else
      dp[i][w] = dp[i-1][w];
  }
}
cout << dp[n][W] << "\n";



// 0/1 KNAPSACK — Which items selected? (Backtracking)


void printSelectedItems(int wt[], int val[], int n, int W, int dp[][1005]){
    int i=n, w=W;
    while(i>0 && w>0){
        if(dp[i][w] != dp[i-1][w]){     // item i-1 taken
            cout << "take wt=" << wt[i-1] << " val=" << val[i-1] << "\n";
            w -= wt[i-1];
        }
        i--;
    }
}




// 0/1 KNAPSACK — Possible exact weight W? (Yes/No)  (Subset Sum)

bool poss[1005][1005];


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
cout << (poss[n][W] ? "YES\n" : "NO\n");




// 0/1 KNAPSACK — Count number of ways to make exact weight W (Subset Count)


long long ways[1005][1005];


for(int i=0;i<=n;i++)
  for(int w=0;w<=W;w++)
    ways[i][w]=0;

ways[0][0]=1;

for(int i=1;i<=n;i++){
  for(int w=0;w<=W;w++){
    ways[i][w] = ways[i-1][w];
    if(wt[i-1] <= w)
      ways[i][w] += ways[i-1][w-wt[i-1]]; 
  }
}
cout << ways[n][W] << "\n";


 // COIN CHANGE — Minimum coins (Unbounded)

const int INF = INT_MAX-1;
int minc[1005][1005];

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
    if(coins[i-1] <= s && minc[i][s-coins[i-1]] != INF){
      minc[i][s] = min(minc[i][s], 1 + minc[i][s-coins[i-1]]); 
    }
  }
}
cout << (minc[n][sum]==INF ? -1 : minc[n][sum]) << "\n";




//COIN CHANGE — Number of ways (Unbounded)


long long cways[1005][1005];


for(int i=0;i<=n;i++)
  for(int s=0;s<=sum;s++)
    cways[i][s]=0;

cways[0][0]=1;

for(int i=1;i<=n;i++){
  for(int s=0;s<=sum;s++){
    cways[i][s] = cways[i-1][s];          
    if(coins[i-1] <= s)
      cways[i][s] += cways[i][s-coins[i-1]]; 
  }
}
cout << cways[n][sum] << "\n";
