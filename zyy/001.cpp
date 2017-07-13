class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++) {
            for (vector<int>::iterator j = i + 1; j != nums.end(); j++) {
                if (*i + *j == target) {
                    vector<int> ret;
                    ret.push_back(i - nums.begin());
                    ret.push_back(j - nums.begin());
                    return ret;
                }
            }
        }
        return vector<int>();
    }
};
