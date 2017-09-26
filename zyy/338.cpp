class Solution {
  public:
    int hammingWeight(uint32_t n) {
        n = (0x55555555 & n) + (0x55555555 & (n >> 1));
        n = (0x33333333 & n) + (0x33333333 & (n >> 2));
        n = (0x0F0F0F0F & n) + (0x0F0F0F0F & (n >> 4));
        n = (0x00FF00FF & n) + (0x00FF00FF & (n >> 8));
        n = (0x0000FFFF & n) + (0x0000FFFF & (n >> 16));

        return (int)n;
    }

    vector<int> countBits(int num) {
        vector<int> ret;
        for (int i(0); i <= num; i++) {
            ret.push_back(hammingWeight((uint32_t)i));
        }
        return ret;
    }
};
