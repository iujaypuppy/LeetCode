class Solution {
  public:
    int mySqrt(int x) {
        if (x < 0) {
            return x;
        }

        int l(0), r(x), ret(0);
        while (l <= r) {
            uint64_t m(((uint64_t)l + r) / 2);
            uint64_t sqr(m * m);
            if (sqr == x) {
                return m;
            }

            if (sqr < x) {
                ret = m;
                l = m + 1;
                continue;
            }
            r = m - 1;
        }

        return ret;
    }
};
