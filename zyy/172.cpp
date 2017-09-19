class Solution {
  public:
    int getFactorNumber(int64_t n, int64_t factor) {
        int ret(0);
        for (int64_t val(factor); val <= n; val *= factor) {
            ret += n / val;
        }

        return ret;
    }
    int trailingZeroes(int n) {
        int twos(0), fives(0);
        twos = getFactorNumber(n, 2);
        fives = getFactorNumber(n, 5);
        return min(twos, fives);
    }
};
