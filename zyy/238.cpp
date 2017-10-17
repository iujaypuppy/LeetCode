class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret;
        for (size_t i(0); i < nums.size(); ++i) {
            if (i == 0) {
                ret.push_back(nums[i]);
                continue;
            }
            ret.push_back(nums[i] * ret[i - 1]);
        }

        for (vector<int>::reverse_iterator i(nums.rbegin());
             i != nums.rend(); ++i) {
            if (i == nums.rbegin()) {
                continue;
            }
            *i *= *(i - 1);
        }

        for (size_t i(0); i < nums.size(); ++i) {
            size_t index(nums.size() - i - 1);
            ret[index] = 1;
            if (index != 0) {
                ret[index] *= ret[index - 1];
            }
            if (index != nums.size() - 1) {
                ret[index] *= nums[index + 1];
            }
        }

        return ret;
    }
};
