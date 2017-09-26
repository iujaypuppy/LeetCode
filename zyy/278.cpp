// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
  public:
    int firstBadVersion(int n) {
        int64_t l(1), r(n), ret(n);
        while (l <= r) {
            int64_t m((l + r) / 2);
            if (isBadVersion(m)) {
                r = m - 1;
                ret = m;
                continue;
            }
            l = m + 1;
        }

        return (int)ret;
    }
};
