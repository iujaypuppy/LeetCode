class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int nums_r = nums.size();
        int nums_c = nums[0].size();      
        if ((nums_r * nums_c) != (r * c)) {
            return nums;
        }
        
        vector<vector<int>> reshape_nums;
        int x = 0, y = 0;
        for (int i = 0; i < r; i++) {
            vector<int> tmp;
            for (int j = 0; j < c; j++) {
                tmp.push_back(nums[y][x]);
                if (x < nums_c - 1) {
                    x++;
                } else {
                    x = 0;
                    y++;
                }
            }
            reshape_nums.push_back(tmp);
        }
        return reshape_nums;
    }
};
