class Solution {
  public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        dp[0] = 0;
        for (int i(0); i < n; i++) {
            for (int j(1); j * j + i <= n; j++) {
                int k(j * j + i);
                dp[k] = min(dp[k], dp[i] + 1);
            }
        }
        return dp[n];
    }
};
