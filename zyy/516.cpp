class Solution {
  public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        int n((int)(s.length()));
        for (int l(n - 1); l >= 0; l--) {
            for (int j(l); j < n; j++) {
                int i(j - l);
                if (i > j || i < 0) {
                    continue;
                }
                if (i - 1 >= 0) {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j]);
                }
                if (j + 1 < n) {
                    dp[i][j] = max(dp[i][j + 1], dp[i][j]);
                }
                if (s[i] == s[j]) {
                    if (i - 1 >= 0 && j + 1 < n) {
                        dp[i][j] = max(dp[i - 1][j + 1] + (i == j ? 1 : 2), dp[i][j]);
                    } else {
                        dp[i][j] = max((i == j ? 1 : 2), dp[i][j]);
                    }
                }
            }
        }

        int ret(0);
        for (int i(0); i < n; i++) {
            ret = max(ret, dp[i][i]);
        }
        return ret;
    }
};
