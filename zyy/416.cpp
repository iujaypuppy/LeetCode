class Solution {
  public:
    bool canPartition(vector<int>& nums) {
        int sum(0);
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            sum += *i;
        }

        if (sum % 2 == 1) {
            return false;
        }

        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            for (int j(sum - *i); j >=0; j--) {
                if (dp[j]) {
                    dp[j + *i] = true;
                }
            }
        }

        return dp[sum];
    }
};
