class Solution {
  public:
    double findMaxAverage(vector<int>& nums, int k) {
        /* Array->sumArray, for convenience of calculating k-sum */
        for (vector<int>::iterator i(nums.begin() + 1);
             i != nums.end(); i++) {
            *i += *(i - 1);
        }

        int result(*(nums.begin() + k - 1));
        for (vector<int>::iterator i(nums.begin() + k);
             i != nums.end(); i++) {
            /* sum from (i - k + 1) to i */
            int sum(*i - *(i - k));
            result = max(result, sum);
        }

        return ((double)result) / k;
    }
};
