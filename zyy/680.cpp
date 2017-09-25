class Solution {
  public:
    bool validPalindromeIterator(string::iterator &begin,
                                 string::iterator &end) {
        while (begin < end) {
            if (*begin != *end) {
                return false;
            }
            begin++;
            end--;
        }

        return true;
    }
    bool validPalindrome(string s) {
        if (s.empty()) {
            return true;
        }

        string::iterator begin(s.begin()), end(s.end() - 1);
        if (validPalindromeIterator(begin, end)) {
            return true;
        }

        string::iterator b(begin + 1), e(end);
        if (validPalindromeIterator(b, e)) {
            return true;
        }

        b = begin;
        e = end - 1;
        if (validPalindromeIterator(b, e)) {
            return true;
        }

        return false;
    }
};
