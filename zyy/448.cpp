class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for (int i(0); i < nums.size(); i++) {
            int owner(i + 1);
            while (nums[i] != owner) {
                int old(nums[i]);
                nums[i] = nums[old - 1];
                nums[old - 1] = old;
                if (old == nums[i]) {
                    break;
                }
            }
        }

        for (int i(0); i < nums.size(); i++) {
            if (i + 1 != nums[i]) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};
