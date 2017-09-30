class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res(0);
        while(n) {
            res += (n & 0x01) ? 1 : 0;
            n = n >> 1;
        }
        return res;
    }
};
