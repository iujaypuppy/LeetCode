class Solution {
  public:
    bool isPowerOfTwo(int n) {
        int maxPowerOfTwo(0x40000000);
        return n > 0 && maxPowerOfTwo % n == 0;
    }
};
