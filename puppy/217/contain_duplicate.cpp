class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            if (i == nums.end() - 1) {
                break;
            } else if (*i == *(i + 1)) {
                return true;
            }
        }
        return false;
    }
};
