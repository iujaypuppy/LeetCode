class Solution {
  public:
    vector<int> constructArray(int n, int k) {
        vector<int> ret;
        int i(1), j(k + 1);
        while (i < j) {
            ret.push_back(i);
            ret.push_back(j);
            i++;
            j--;
        }

        if (i == j) {
            ret.push_back(i);
        }

        for (int i(k + 2); i <= n; ++i) {
            ret.push_back(i);
        }

        return ret;
    }
};
