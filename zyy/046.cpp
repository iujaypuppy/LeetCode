class Solution {
  public:
    void swap(int &a, int &b) {
        int tmp(a);
        a = b;
        b = tmp;
    }
    void permute(vector<int>::iterator begin, vector<int>::iterator end,
                 vector<int> &current, vector<vector<int>> &ret) {
        if (begin == end) {
            ret.push_back(current);
            return;
        }
        for (vector<int>::iterator i(begin); i != end; i++) {
            swap(*i, *begin);
            current.push_back(*begin);
            permute(begin + 1, end, current, ret);
            current.erase(current.end() - 1);
            swap(*i, *begin);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> ret;
        permute(nums.begin(), nums.end(), tmp, ret);
        return ret;
    }
};
