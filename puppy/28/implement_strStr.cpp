class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t lenHay(haystack.size()), lenNed(needle.size());
        if (lenHay < lenNed) {
            return -1;
        }
        if (lenHay == lenNed && lenHay == 0) {
            return 0;
        }
        
        for (size_t i(0); i < lenHay; i++) {
            if (i + lenNed > lenHay) {
                return -1;
            }
            bool found = true;
            for (size_t j(0); j < lenNed; j++) {
                if (haystack[i + j] != needle[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return i;
            }
        }
        return -1;
    }
};
