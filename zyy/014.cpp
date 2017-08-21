class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        string prefix = *strs.begin();
        for (vector<string>::iterator i = strs.begin() + 1; i != strs.end(); i++) {
            string& str = *i;
            string nextPrefix;
            string::iterator cp, cs;
            for (cp = prefix.begin(), cs = str.begin();
                 cp != prefix.end() && cs != str.end();
                 cp++, cs++) {
                if (*cp == *cs) {
                    nextPrefix += *cp;
                } else {
                    break;
                }
            }

            prefix = nextPrefix;
        }
        return prefix;
    }
};
