class Solution {
  public:
    string licenseKeyFormatting(string S, int K) {
        string s;
        for (string::iterator c(S.begin()); c != S.end(); c++) {
            if (*c != '-') {
                s += toupper(*c);
            }
        }
        string ret;
        size_t length(s.length());
        for (size_t i(0); i < length; i++) {
            ret = *(s.rbegin() + i) + ret;
            if (i != length - 1 && i % K == K - 1) {
                ret = "-" + ret;
            }
        }

        return ret;
    }
};
