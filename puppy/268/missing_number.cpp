class Solution {
public:
    int missingNumber(vector<int>& nums) {      
        size_t n = nums.size();
        int missing_sum = 0;
        int sum = (1 + n) * n / 2;      
        for (size_t i(0); i < n; i++) {
            missing_sum += nums[i];
        }     
        return sum - missing_sum;
    }
};
