class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single_one = 0;
        for (int i = 0; i < nums.size(); i++) {
            single_one ^= nums[i];
        }
        return single_one;
    }
};
