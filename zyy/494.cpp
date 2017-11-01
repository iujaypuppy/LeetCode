class Solution {
  public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return (abs(S) == abs(*nums.rbegin()) ? 1 : 0) *
                    (S == 0 ? 2 : 1);
        }

        int k(*nums.rbegin());
        nums.erase(nums.end() - 1);
        int ret(0);
        ret += findTargetSumWays(nums, S + k);
        ret += findTargetSumWays(nums, S - k);
        nums.push_back(k);
        return ret;
    }
};
