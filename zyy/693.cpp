class Solution {
  public:
    bool hasAlternatingBits(int n) {
        unsigned int unsignedN((unsigned int)n);
        unsigned int prev(unsignedN & 1);
        unsignedN >>= 1;
        while (unsignedN) {
            if ((unsignedN & 1) == prev) {
                return false;
            }
            prev = unsignedN & 1;
            unsignedN >>= 1;
        }
        return true;
    }
};
