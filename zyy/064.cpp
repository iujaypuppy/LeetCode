class Solution {
  public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        size_t m(grid.size()), n(grid[0].size());
        int sum(0);
        for (size_t i(0); i < m; i++) {
            sum += grid[i][0];
            grid[i][0] = sum;
        }
        sum = 0;
        for (size_t i(0); i < n; i++) {
            sum += grid[0][i];
            grid[0][i] = sum;
        }

        for (size_t i(1); i < m; i++) {
            for (size_t j(1); j < n; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }
};
