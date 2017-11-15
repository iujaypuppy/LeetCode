class Solution {
  public:
    class String {
      public:
        int x, y;
        String(int xx = 0, int yy = 0): x(xx), y(yy) {}
        String(string s = ""): x(0), y(0) {
            for (string::iterator i(s.begin()); i != s.end(); i++) {
                if (*i == '0') {
                    x++;
                } else {
                    y++;
                }
            }
        }
    };
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (vector<string>::iterator s(strs.begin()); s != strs.end(); s++) {
            String str(*s);
            for (int i(m); i >= 0; i--) {
                int x(i + str.x);
                if (x > m) {
                    continue;
                }
                for (int j(n); j >= 0; j--) {
                    int y(j + str.y);
                    if (y > n) {
                        continue;
                    }
                    dp[x][y] = max(dp[x][y], dp[i][j] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
