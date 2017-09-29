class Solution {
public:
    int findLHS(vector<int>& nums) {
        int LHS(0);
        map<int, int> greater, less;
        // Use the negative or postive to judge whether greater[i] exist i+1;
        for(size_t i(0); i < nums.size(); i++) {
            if (greater.find(nums[i]) != greater.end()) {
                greater[nums[i]] = (greater[nums[i]] > 0) ? greater[nums[i]] + 1 : greater[nums[i]] - 1;
                LHS = max(LHS, greater[nums[i]]);
            } else {
                greater.insert(pair<int, int>(nums[i], -1));
            }
            
            if (less.find(nums[i]) != less.end()) {
                less[nums[i]] = (less[nums[i]] > 0) ? less[nums[i]] + 1 : less[nums[i]] - 1;
                LHS = max(LHS, less[nums[i]]);
            } else {
                less.insert(pair<int, int>(nums[i], -1));
            }
            
            if (greater.find(nums[i] + 1) != greater.end()) {
                greater[nums[i] + 1] = abs(greater[nums[i] + 1]) + 1;
                LHS = max(LHS, greater[nums[i] + 1]);
            }
            if (less.find(nums[i] - 1) != less.end()) {
                less[nums[i] - 1] = abs(less[nums[i] - 1]) + 1;
                LHS = max(LHS, less[nums[i] - 1]);
            }
        }
        return LHS;
    }
};
