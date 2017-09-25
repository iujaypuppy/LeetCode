class Solution {
  public:
    bool isPalindrome(string::iterator begin, string::iterator end) {
        for (string::iterator i(begin); i <= end; i++) {
            *i = toupper(*i);
        }
        while (begin < end) {
            while (begin < end && !isalpha(*begin) && !isdigit(*begin)) {
                begin++;
            }
            while (begin < end && !isalpha(*end) && !isdigit(*end)) {
                end--;
            }
            if (*begin != *end) {
                return false;
            }
            begin++;
            end--;
        }

        return true;
    }
    bool isPalindrome(string s) {
        return s.empty() || isPalindrome(s.begin(), s.end() - 1);
    }
};
