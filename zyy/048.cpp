class Solution {
  public:
    void rotate(vector<vector<int>>& matrix) {
        int n((int)matrix.size());
        for (int i(0); i < n; i++) {
            for (int j(0); j < i; j++) {
                int tmp(matrix[i][j]);
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

        for (int i(0); i < n; i++) {
            for (int j(0); j < n / 2; j++) {
                int tmp(matrix[i][j]);
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = tmp;
            }
        }
    }
};
