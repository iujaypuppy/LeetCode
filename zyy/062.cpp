#include <cstdint>

class Solution {
  public:
    int uniquePaths(int m, int n) {
        m--;
        n--;
        if (m < 0 || n < 0) {
            return 0;
        }

        if (m == 0 || n == 0) {
            return 1;
        }

        if (m < n) {
            int tmp(m);
            m = n;
            n = tmp;
        }

        uint64_t ret(1);
        for (uint64_t i(0); i < n; i++) {
            ret *= m + n - i;
            ret /= i + 1;
        }

        return ret;
    }
};

