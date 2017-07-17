class Solution {
  public:
    void extendPalindromeSubstring(string::iterator &begin,
                                   string::iterator &end,
                                   const string &s) {
        while (true) {
            if (*begin != *(end - 1)) {
                /* back to last workable case */
                begin++;
                end--;
                break;
            }
            if (begin == s.begin() ||
                end == s.end()) {
                break;
            }
            begin--;
            end++;
        }
    }
    string longestPalindrome(string s) {
        int max = 0;
        string::iterator solutionBegin(s.end()), solutionEnd(s.end());
        for (string::iterator itr = s.begin(); itr < s.end(); itr++) {
            string::iterator begin, end;
            /*
              case: the symmetry axis is at the position of itr
              abcda
                ^
               itr
            */
            begin = itr;
            end = itr + 1;
            extendPalindromeSubstring(begin, end, s);
            if (end - begin > max) {
                max = end - begin;
                solutionBegin = begin;
                solutionEnd = end;
            }

            /*
              case: the symmetry axis is at the position of itr
              abba
               ^
              itr
            */
            if (itr + 1 == s.end()) {
                /* itr is the last character, this case doesn't exist */
                continue;
            }
            begin = itr;
            end = itr + 2;
            extendPalindromeSubstring(begin, end, s);
            if (end - begin > max) {
                max = end - begin;
                solutionBegin = begin;
                solutionEnd = end;
            }
        }
        return string(solutionBegin, solutionEnd);
    }
};
