class Solution {
  public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() < 3) {
            int result(0);
            for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
                result = max(result, *i);
            }

            return result;
        }

        vector<int> maxIfWeRob(nums.size());
        maxIfWeRob[0] = max(nums[0], 0);
        maxIfWeRob[1] = max(nums[1], 0);
        int result(max(maxIfWeRob[0], maxIfWeRob[1])), formerMax(0);
        for (size_t i(2); i < nums.size(); i++) {
            formerMax = max(formerMax, maxIfWeRob[i - 2]);
            maxIfWeRob[i] = formerMax + nums[i];
            result = max(maxIfWeRob[i], result);
        }

        return result;
    }
};
