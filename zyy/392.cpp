class Solution {
  public:
    bool isSubsequence(string s, string t) {
        string::iterator cur(t.begin());
        for (string::iterator i(s.begin()); i != s.end(); i++) {
            while (cur != t.end() && *cur != *i) {
                cur++;
            }
            if (cur == t.end()) {
                return false;
            }
            cur++;
        }

        return true;
    }
};
