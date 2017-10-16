class Solution {
  public:
    int getArea(vector<vector<int>> &grid, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) {
            return 0;
        }

        if (grid[x][y] == 0) {
            return 0;
        }

        grid[x][y] = 0;
        return getArea(grid, x + 1, y) + getArea(grid, x - 1, y) +
                getArea(grid, x, y + 1) + getArea(grid, x, y - 1) + 1;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret(0);
        for (size_t i(0); i < grid.size(); ++i) {
            for (size_t j(0); j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    ret = max(ret, getArea(grid, i, j));
                }
            }
        }

        return ret;
    }
};
