class Solution {
  public:
    vector<int> findDuplicates(vector<int>& nums) {
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            (*i)--;
        }

        for (size_t i(0); i < nums.size(); i++) {
            int last((int)nums.size());
            while (nums[i] != (int)i && last != nums[i]) {
                int tmp(nums[nums[i]]);
                last = nums[nums[i]] = nums[i];
                nums[i] = tmp;
            }
        }

        vector<int> ret;
        for (size_t i(0); i < nums.size(); i++) {
            if (nums[i] != (int)i) {
                ret.push_back(nums[i] + 1);
            }
        }

        return ret;
    }
};
