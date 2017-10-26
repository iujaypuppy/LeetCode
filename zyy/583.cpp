class Solution {
  public:
    int minDistance(string word1, string word2) {
        int m((int)word1.size()), n((int)word2.size());
        vector<vector<int>> t(m + 1, vector<int>(n + 1));
        for (int i(0); i < m + 1; i++) {
            t[i][0] = i;
        }
        for (int i(0); i < n + 1; i++) {
            t[0][i] = i;
        }

        for (int i(1); i < m + 1; i++) {
            for (int j(1); j < n + 1; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    t[i][j] = t[i - 1][j - 1];
                } else {
                    t[i][j] = min(t[i - 1][j], t[i][j - 1]) + 1;
                }
            }
        }

        return t[m][n];
    }
};
