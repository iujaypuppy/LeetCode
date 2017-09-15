class Solution {
  public:
    int missingNumber(vector<int>& nums) {
        nums.resize(nums.size() + 1, -1);
        for (size_t i(0); i < nums.size(); i++) {
            while (i != nums[i] && nums[i] != -1) {
                int old(nums[nums[i]]);
                nums[nums[i]] = nums[i];
                nums[i] = old;
            }
        }

        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            if (*i < 0) {
                return i - nums.begin();
            }
        }

        return -1;
    }
};
