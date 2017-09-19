class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> res;
        vector<int> sort_nums(nums);
        sort(sort_nums.begin(), sort_nums.end());
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            if (*i == *(sort_nums.end() - 1)) {
                res.push_back("Gold Medal");
            } else if (*i == *(sort_nums.end() - 1)) {
                res.push_back("Gold Medal");
            } else if (*i == *(sort_nums.end() - 1)) {
                res.push_back("Gold Medal");
            } else {
                res.push_back(to_string(i - nums)
            }
        }
    }
};
