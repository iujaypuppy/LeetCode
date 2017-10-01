class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_sum(0), pre_sum(0);
        for (size_t i(0); i < k; i++) {
            pre_sum += nums[i];
        }
        max_sum = pre_sum;
        
        for (size_t i(1); i <= nums.size() - k; i++) {
            double cur_sum = pre_sum - nums[i - 1] + nums[i + k - 1];
            max_sum = (max_sum > cur_sum) ? max_sum : cur_sum;
            pre_sum = cur_sum;
        }
        return max_sum / k;
    }
};
