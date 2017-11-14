#include <vector>
using namespace std;

class Solution {
  public:
    void combinationSum(vector<int>::iterator begin, vector<int>::iterator end,
                        vector<int> &cur, int target,
                        vector<vector<int>> &ret) {
        if (target == 0) {
            ret.push_back(cur);
            return;
        }
        if (begin == end) {
            return;
        }

        for (int i(0); i * *begin <= target; i++) {
            cur.resize(cur.size() + i, *begin);
            combinationSum(begin + 1, end, cur, target - i * *begin, ret);
            cur.resize(cur.size() - i);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> tmp;
        combinationSum(candidates.begin(), candidates.end(), tmp, target, ret);
        return ret;
    }
};
