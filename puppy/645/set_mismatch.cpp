class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int duplicated, lost;
        int old_sum(1), new_sum(nums[0]);
        for(size_t i(1); i < nums.size(); i++) {
            old_sum += (i + 1);
            new_sum += nums[i];
            if(nums[i] == nums[i - 1]) {
                duplicated = nums[i];
            }
        }
        lost = duplicated + (old_sum - new_sum);
        
        vector<int> res;
        res.push_back(duplicated);
        res.push_back(lost);
        return res;
    }
};
