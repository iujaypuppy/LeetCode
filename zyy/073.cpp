class Solution {
  public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }
        int m((int)matrix.size()), n((int)matrix[0].size());
        vector<bool> r(m, false), c(n, false);

        for (int i(0); i < m; i++) {
            for (int j(0); j < n; j++) {
                if (matrix[i][j] == 0) {
                    r[i] = true;
                    c[j] = true;
                }
            }
        }

        for (int i(0); i < m; i++) {
            for (int j(0); j < n; j++) {
                if (r[i] || c[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
