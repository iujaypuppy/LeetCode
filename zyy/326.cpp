class Solution {
  public:
    bool isPowerOfThree(int n) {
        int maxPowerInt(0x4546b3db);
        return n > 0 && maxPowerInt % n == 0;
    }
};
