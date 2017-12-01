class Solution {
  public:
    bool destroyIsland(vector<vector<char>> &grid, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) {
            return false;
        }
        if (grid[x][y] == '0') {
            return false;
        }
        grid[x][y] = '0';

        destroyIsland(grid, x - 1, y);
        destroyIsland(grid, x + 1, y);
        destroyIsland(grid, x, y - 1);
        destroyIsland(grid, x, y + 1);

        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        int m((int)grid.size()), n((int)grid[0].size()), count(0);
        for (int i(0); i < m; i++) {
            for (int j(0); j < n; j++) {
                if (destroyIsland(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};
