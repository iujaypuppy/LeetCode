class Solution {
  public:
    /* Fibonacci */
    int climbStairs(int n) {
        int prev(1), preprev(0), result(0);
        for (int i(0); i < n; i++) {
            result = prev + preprev;
            preprev = prev;
            prev = result;
        }

        return result;
    }
};
