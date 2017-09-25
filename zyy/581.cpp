class Solution {
  public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        int left(nums.size()), right(-1);
        for (size_t i(0); i < nums.size(); i++) {
            if (sorted[i] != nums[i]) {
                left = min((int)i, left);
                right = max((int)i, right);
            }
        }

        return max(0, right - left + 1);
    }
};
