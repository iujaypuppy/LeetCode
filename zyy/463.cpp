class Solution {
  public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result(0);
        for (size_t i(0); i < grid.size(); i++) {
            for (size_t j(0); j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    continue;
                }

                /* left */
                if (j == 0 || grid[i][j - 1] == 0) {
                    result++;
                }

                /* right */
                if (j == grid[i].size() - 1 || grid[i][j + 1] == 0) {
                    result++;
                }

                /* up */
                if (i == 0 || grid[i - 1][j] == 0) {
                    result++;
                }

                /* down */
                if (i == grid.size() - 1 || grid[i + 1][j] == 0) {
                    result++;
                }
            }
        }
        return result;
    }
};
