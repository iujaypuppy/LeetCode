class Solution {
  public:
    uint64_t reverse(uint64_t x) {
        int64_t reversedVal(0);
        const int base(10);

        while (x != 0) {
            uint64_t digit(x % base);
            x /= base;
            reversedVal = reversedVal * base + digit;
        }

        return reversedVal;
    }

    int largestPalindrome(int n) {
        uint64_t upper(pow(10, n) - 1), lower(pow(10, n - 1));
        uint64_t pUpper(upper * upper), pLower(lower * lower);
        /* 2n bits condition */
        for (uint64_t half(upper); half >= lower; half--) {
            uint64_t palindrome(half * (upper + 1) + reverse(half));
            if (palindrome < pLower || palindrome >pUpper) {
                continue;
            }
            for (uint64_t i(max(lower, palindrome / upper + (palindrome % upper == 0 ? 0 : 1)));
                 i * lower <= palindrome && i <= upper; i++) {
                if (palindrome % i == 0) {
                    return (int)(palindrome % 1337);
                }
            }
        }
        /* 2n - 1 bits condition */
        for (uint64_t half(upper); half >= lower; half--) {
            uint64_t palindrome(half * lower + reverse(half / 10));
            if (palindrome < pLower || palindrome >pUpper) {
                continue;
            }
            for (uint64_t i(max(lower, palindrome / upper + (palindrome % upper == 0 ? 0 : 1)));
                 i * lower <= palindrome && i <= upper; i++) {
                if (palindrome % i == 0) {
                    return (int)(palindrome % 1337);
                }
            }
        }

        return 0;
    }
};
