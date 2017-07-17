class Solution {
  public:
    int reverse(int x) {
        int unsignedVal = x > 0 ? x : -x;
        int sign = x > 0 ? 1 : -1;
        int64_t reversedVal = 0;
        /*
          if you change this to 16, you can use this function
          for hexadecimal, 8 for octal, etc.
         */
        const int base = 10;

        while (unsignedVal != 0) {
            int digit = unsignedVal % base;
            unsignedVal /= base;
            reversedVal = reversedVal * 10 + digit;
        }

        reversedVal *= sign;
        int ret = (int32_t)reversedVal;
        /* check for overflowing */
        if (ret != reversedVal) {
            return 0;
        }

        return ret;
    }
};
