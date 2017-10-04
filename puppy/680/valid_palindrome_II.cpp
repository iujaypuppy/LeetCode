class Solution {
public:
    bool validPalindrome(string s) {
        size_t len(s.size());
        if (len <= 1) {
            return true;
        }
        size_t i(0), j(len - 1);
        while (i < j) {
            if (s[i] != s[j]) {
                return isValidPalindromeStr(s, i, j - 1)
                    || isValidPalindromeStr(s, i + 1, j);
            }
            i++;
            j--;
        }
        return true;
    }
    
    bool isValidPalindromeStr(string s, size_t i, size_t j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
