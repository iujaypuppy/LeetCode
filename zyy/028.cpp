class Solution {
  public:
    int strStr(string haystack, string needle) {
        size_t needleLength(needle.length());

        if (needleLength == 0) {
                return 0;
        }

        size_t haystackLength(haystack.length());

        if (needleLength > haystackLength) {
                return -1;
        }

        haystackLength =  haystackLength - needleLength + 1;

        for (size_t i(0); i < haystackLength; i++) {
            size_t j(0);
            for (; j < needleLength; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == needleLength) {
                return i;
            }
        }

        return -1;
    }
};
