class Solution {
  public:
    /* Quadratic inequation */
    int arrangeCoins(int n) {
        return (sqrt(8 * (double)n + 1) - 1) / 2;
    }
};
