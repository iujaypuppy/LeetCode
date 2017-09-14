class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }

        sort(nums.begin(), nums.end());

        for (vector<int>::iterator i(nums.begin() + 1);
             i != nums.end(); i++) {
            if (*i == *(i - 1)) {
                return true;
            }
        }

        return false;
    }
};
