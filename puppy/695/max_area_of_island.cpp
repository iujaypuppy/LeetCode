class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res(0);
        size_t row(grid.size());
        for (size_t i(0); i < row; i++) {
            size_t col(grid[i].size());
            for (size_t j(0); j < col; j++) {
                int cur = maxAreaOfIsland(grid, row, col, i, j);
                res = (res > cur) ? res : cur;
            }
        }
        return res;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid, size_t row, size_t col, size_t i, size_t j) {
        if (!grid[i][j]) {
            return 0;
        }
        int res(1);
        grid[i][j] = 0;
        if (i >= 1) {
            res += maxAreaOfIsland(grid, row, col, i - 1, j);
        }
        if (i + 1 < row) {
            res += maxAreaOfIsland(grid, row, col, i + 1, j);
        }
        if (j >= 1) {
            res += maxAreaOfIsland(grid, row, col, i, j - 1);
        }
        if (j + 1 < col) {
            res += maxAreaOfIsland(grid, row, col, i, j + 1);
        }
        return res;
    }
};
