class Solution {
  public:
    class Gadgets {
      private:
        static const size_t TOTAL = 26;
        int count[TOTAL];
      public:
        Gadgets(const string &str) {
            for (size_t i(0); i < TOTAL; i++) {
                count[i] = 0;
            }

            for (string::const_iterator i(str.begin()); i != str.end(); i++) {
                count[*i - 'a']++;
            }
        }
        bool isUnique(char c) const { return count[c - 'a'] == 1; }
    };
    int firstUniqChar(string s) {
        Gadgets gadgets(s);
        for (string::iterator i(s.begin()); i != s.end(); i++) {
            if (gadgets.isUnique(*i)) {
                return i - s.begin();
            }
        }
        return -1;
    }
};
