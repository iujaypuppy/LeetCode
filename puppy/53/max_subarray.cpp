class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // sum[i] = max(sum[i-1]+nums[i], nums[i])
        // sum[i] is the largest sum containing the nums[i]
        int res(nums[0]), pre_i_sum(nums[0]);
        size_t size(nums.size());
        for (size_t i(1); i < size; i++) {
            pre_i_sum = max(pre_i_sum + nums[i], nums[i]);
            res = max(res, pre_i_sum);
        }
        return res;
    }
};
