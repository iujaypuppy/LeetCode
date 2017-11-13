class Solution {
  public:
    void combine(int l, int r, int k, vector<int> &cur, vector<vector<int>> &ret) {
        if (k == 0) {
            ret.push_back(cur);
            return;
        }
        if (l > r) {
            return;
        }

        for (int i(l); i <= r; i++) {
            cur.push_back(i);
            combine(i + 1, r, k - 1, cur, ret);
            cur.erase(cur.end() - 1);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        vector<vector<int>> ret;
        combine(1, n, k, tmp, ret);
        return ret;
    }
};
