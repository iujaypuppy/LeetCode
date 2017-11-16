class Solution {
  public:
    void findSubsequences(vector<int>::iterator begin, vector<int>::iterator end,
                          vector<int> &cur,
                          vector<vector<int>> &ret) {
        if (begin == end) {
            return;
        }

        vector<bool> chosen(201, false);
        for (vector<int>::iterator i(begin); i != end; i++) {
            if (chosen[*i + 100]) {
                continue;
            }
            chosen[*i + 100] = true;
            if (!cur.empty() && *i < *cur.rbegin()) {
                continue;
            }
            cur.push_back(*i);
            if (cur.size() >= 2) {
                ret.push_back(cur);
            }
            findSubsequences(i + 1, end, cur, ret);
            cur.erase(cur.end() - 1);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        findSubsequences(nums.begin(), nums.end(), tmp, ret);
        return ret;
    }
};
