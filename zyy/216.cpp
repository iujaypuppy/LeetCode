class Solution {
  public:
    void combinationSum3(int k, int start, int sum, int n,
                         vector<bool> &used,
                         vector<vector<int>> &solutions) {
        if (k == 0) {
            if (sum == n) {
                vector<int> current;
                for (int i(1); i < 10; i++) {
                    if (used[i]) {
                        current.push_back(i);
                    }
                }
                solutions.push_back(current);
            }
            return;
        }

        for (int i(start); i < 10; i++) {
            if (used[i]) {
                continue;
            }

            used[i] = true;
            combinationSum3(k - 1, i + 1, sum + i, n, used, solutions);
            used[i] = false;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<bool> used(10, false);
        combinationSum3(k, 1, 0, n, used, ret);
        return ret;
    }
};
