class Solution {
  public:
    string expand(const string &s) {
        string ret;
        for (string::const_iterator i(s.begin()); i != s.end(); i++) {
            char n(*i);
            string::const_iterator j(i + 1);
            while (j != s.end() && *j == n) {
                j++;
            }
            ret += to_string(j - i) + n;
            i = j - 1;
        }
        return ret;
    }
    string countAndSay(int n) {
        if (n <= 0) {
            return "";
        }

        string cas("1");
        for (int i(1); i < n; i++) {
            cas = expand(cas);
        }

        return cas;
    }
};
