class Solution {
  public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> length(nums.size(), 1);
        int ret(1);
        for (size_t i(0); i < nums.size(); i++) {
            for (size_t j(0); j < i; j++) {
                if (nums[j] < nums[i]) {
                    length[i] = max(length[i], length[j] + 1);
                    ret = max(ret, length[i]);
                }
            }
        }
        return ret;
    }
};
