#include "dp_solvers.h"
#include <vector>
#include <algorithm>

using namespace std;

// ✅ Knapsack (Memoization)
int knapsackMemoizationUtil(int W, vector<int>& wt, vector<int>& val, int n, vector<vector<int>>& dp) {
    if (n == 0 || W == 0) return 0;
    if (dp[n][W] != -1) return dp[n][W];

    if (wt[n - 1] <= W)
        return dp[n][W] = max(val[n - 1] + knapsackMemoizationUtil(W - wt[n - 1], wt, val, n - 1, dp),
                              knapsackMemoizationUtil(W, wt, val, n - 1, dp));
    else
        return dp[n][W] = knapsackMemoizationUtil(W, wt, val, n - 1, dp);
}

int knapsackMemoization(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    return knapsackMemoizationUtil(W, wt, val, n, dp);
}

// ✅ LCS (Longest Common Subsequence)
int lcs(string X, string Y, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

// ✅ Coin Change (Tabulation)
int coinChangeWays(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= amount; j++) {
            if (coins[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][amount];
}
