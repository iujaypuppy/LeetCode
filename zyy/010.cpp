class Solution {
  public:
    bool isMatch(string s, string p) {
        if (p.length() == 0) {
            return s.length() == 0;
        }

        if (p[0] == '*') {
            /* invalid pattern */
            return false;
        }
        if (p[0] == '.') {
            if (p.length() > 1 && p[1] == '*') {
                /* match everthing (.*) pattern: enumerate how many characters to be matched */
                for (size_t i = 0; i <= s.length(); i++) {
                    if (isMatch(s.substr(i), p.substr(2))) {
                        return true;
                    }
                }
                return false;
            }
            if (s.length() > 0) {
                /*
                  if this dot matches something, it must match
                  the first character of s
                 */
                p[0] = s[0];
            } else {
                /* since s is empty, this dot can be anything */
                p[0] = 'Z';
            }
        }

        if (p.length() > 1 && p[1] == '*') {
            /* Z* case: enumerate how many character this * can represent */
            // match nothing
            if (isMatch(s, p.substr(2))) {
                return true;
            }
            for (size_t i = 0; i < s.length(); i++) {
                if (s[i] != p[0]) {
                    /* cannot match any more */
                    break;
                }
                if (isMatch(s.substr(i + 1), p.substr(2))) {
                    return true;
                }
            }

            return false;
        } else {
            if (p[0] != s[0]) {
                return false;
            }

            return isMatch(s.substr(1), p.substr(1));
        }
    }
};
