class Solution {
  public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int up(1), down(1);
        for (vector<int>::iterator i(nums.begin() + 1); i != nums.end(); i++) {
            if (*i > *(i - 1)) {
                up = max(up, down + 1);
            } else if (*i < *(i - 1)) {
                down = max(down, up + 1);
            }
        }
        return max(up, down);
    }
};
