class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp(nums);
        
        size_t len(nums.size());
        k = k % len;
        for (size_t i(0); i < len; i++) {
            if (i < k) {
                nums[i] = tmp[len - k + i];
            } else {
                nums[i] = tmp[i - k];
            }
        }
    }
};
