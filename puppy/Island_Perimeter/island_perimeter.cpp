class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        size_t grid_r = grid.size();
        size_t grid_c = grid[0].size();
        for (int i = 0; i < grid_r; i++) {
            for (int j = 0; j < grid_c; j++) {
                if (grid[i][j]) {
                    if ((j == 0) || (grid[i][j-1] == 0)) {
                        perimeter++;
                    }
                    if ((i == 0) || (grid[i-1][j] == 0)) {
                        perimeter++;
                    }
                    if ((j == grid_c - 1) || (grid[i][j+1] == 0)) {
                        perimeter++;
                    }                  
                    if ((i == grid_r - 1) || (grid[i+1][j] == 0)) {
                        perimeter++;
                    }
                }
            }
        }
        return perimeter;
    }
};
