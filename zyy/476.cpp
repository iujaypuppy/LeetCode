class Solution {
  public:
    int findComplement(int num) {
        unsigned int target((unsigned int)num);
        unsigned int mask(target);

        mask |= mask >> 16;
        mask |= mask >> 8;
        mask |= mask >> 4;
        mask |= mask >> 2;
        mask |= mask >> 1;
        return (int)((~target) & mask);
    }
};
