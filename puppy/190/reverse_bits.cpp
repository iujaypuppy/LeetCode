class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res(0x00000000);
        const static int bitNums(32);
        for (int i(0); i < bitNums; i++) {
            res |= ((n & 0x01) << (bitNums - i - 1));
            n >>= 1;
        }
        return res;
    }
};
