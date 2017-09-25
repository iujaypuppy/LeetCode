class Solution {
  public:
    uint32_t reverseBits(uint32_t n, uint32_t width) {
        if (width == 0) {
            return n;
        }

        uint32_t half(width >> 1);
        return reverseBits(n >> half, half) |
                (reverseBits(n & ((1 << half) - 1), half) << half);
    }
    uint32_t reverseBits(uint32_t n) {
        return reverseBits(n, 32);
    }
};
