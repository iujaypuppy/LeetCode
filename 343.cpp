class Solution {
  public:
    int integerBreak(int n) {
        int *mul(new int[n + 1]);

        mul[0] = 0;
        for (int i(1); i <= n; i++) {
            mul[i] = 1;
            for (int j(0); j < i; j++) {
                mul[i] = max(mul[i], mul[j] * mul[i - j]);
                mul[i] = max(mul[i], mul[j] * (i - j));
                mul[i] = max(mul[i], j * (i - j));
            }
        }

        int ret(mul[n]);
        delete [] mul;
        return ret;
    }
};
