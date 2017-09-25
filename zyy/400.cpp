class Solution {
  public:
    int findNthDigit(int n) {
        /* "max" means the maximum number within "bits - 1" bits */
        uint64_t bits(1), max(0), totalBits(0), nextTotalBits(9), range(9);
        while (n > nextTotalBits) {
            bits++;
            totalBits = nextTotalBits;
            range *= 10;
            nextTotalBits += range * bits;
            max = max * 10 + 9;
        }

        /* The answer is in "number" */
        uint64_t number((n - totalBits - 1) / bits + max + 1), offset((n - totalBits - 1) % bits);
        return to_string(number)[offset] - '0';
    }
};
