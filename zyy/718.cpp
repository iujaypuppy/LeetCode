class Solution {
  public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m((int)A.size()), n((int)B.size());
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ret(0);

        for (int i(0); i < m; i++) {
            for (int j(0); j < n; j++) {
                if (A[i] != B[j]) {
                    continue;
                }
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }

                ret = max(dp[i][j], ret);
            }
        }

        return ret;
    }
};
