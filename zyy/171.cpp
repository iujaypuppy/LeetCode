class Solution {
  public:
    int titleToNumber(string s) {
        const int base(26);
        int result(0);
        for (string::iterator i(s.begin()); i != s.end(); i++) {
            result = result * base + *i - 'A' + 1;
        }

        return result;
    }
};
