class Solution {
public:
    int rob(vector<int>& nums) {
        size_t len = nums.size();
        if (len == 0) {
            return 0;
        }
        if (len >= 2) {
            nums[1] = (nums[1] > nums[0]) ? nums[1] : nums[0];
        }
        
        for (size_t i(2); i < len; i++) {
            if ((nums[i - 2] + nums[i]) > nums[i - 1]) {
                nums[i] = nums[i - 2] + nums[i];
            } else {
                nums[i] = nums[i - 1];
            }
        }
        return nums[len - 1];
    }
};
