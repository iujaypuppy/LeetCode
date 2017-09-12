class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
            int index = abs(*iter) - 1;
            if (nums[index] > 0) {
                nums[index] = 0 - nums[index];
            }
        }
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
            if (*iter > 0) {
                res.push_back(iter - nums.begin() + 1);
            }
        }
        return res;
    }
};
