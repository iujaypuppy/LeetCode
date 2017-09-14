class Solution {
  public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        /* +, +, + */
        int allPositive(*(nums.end() - 1) *
                        *(nums.end() - 2) *
                        *(nums.end() - 3));

        /* -, - , + */
        int twoNegative(*nums.begin() *
                        *(nums.begin() + 1) *
                        *(nums.end() - 1));

        return max(allPositive, twoNegative);
    }
};
