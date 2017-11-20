class Solution {
  public:
    void subsetsWithDup(vector<int>::iterator begin, vector<int>::iterator end,
                        vector<int> &cur, vector<vector<int>> &ret) {
        ret.push_back(cur);
        if (begin == end) {
            return;
        }

        for (vector<int>::iterator i(begin); i != end; i++) {
            if (i != begin && *i == *(i - 1)) {
                continue;
            }
            cur.push_back(*i);
            subsetsWithDup(i + 1, end, cur, ret);
            cur.erase(cur.end() - 1);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> tmp;
        subsetsWithDup(nums.begin(), nums.end(), tmp, ret);
        return ret;
    }
};
