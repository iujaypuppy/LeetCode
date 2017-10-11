class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortNums(nums);
        sort(sortNums.begin(), sortNums.end());
        
        size_t start(0), end(0), len(nums.size());
        for (size_t i(0); i < len; i++) {
            if (nums[i] != sortNums[i]) {
                start = i;
                break;
            }
        }
        for (size_t i(len); i > 0; i--) {
            if (nums[i - 1] != sortNums[i - 1]) {
                end = i;
                break;
            }
        }
        
        return end - start;
    }
};
