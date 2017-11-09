class Solution {
  public:
    void subsets(vector<int>::iterator begin, vector<int>::iterator end,
                 vector<int> &current,
                 vector<vector<int>> &power) {
        if (begin == end) {
            power.push_back(current);
            return;
        }

        current.push_back(*begin);
        subsets(begin + 1, end, current, power);
        current.erase(current.end() - 1);
        subsets(begin + 1, end, current, power);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        subsets(nums.begin(), nums.end(), tmp, ret);
        return ret;
    }
};
