class Solution {
  public:
    class Gadgets {
      private:
        static const size_t TOTAL = 26;
        int count[TOTAL];
      public:
        Gadgets(const string &str = "") {
            for (size_t i(0); i < TOTAL; i++) {
                count[i] = 0;
            }

            for (string::const_iterator i(str.begin()); i != str.end(); i++) {
                count[(unsigned char)*i - 'a']++;
            }
        }
        void dec(char c) {
            count[(unsigned char)c - 'a']--;
        }
        void inc(char c) {
            count[(unsigned char)c - 'a']++;
        }
        bool operator==(const Gadgets &other) const {
            for (size_t i(0); i < TOTAL; i++) {
                if (count[i] != other.count[i]) {
                    return false;
                }
            }
            return true;
        }
    };
    bool checkInclusion(string s1, string s2) {
        size_t l1(s1.length()), l2(s2.length());
        Gadgets g1(s1), g2(s2.substr(0, l1));
        if (g1 == g2) {
            return true;
        }
        for (size_t i(l1); i <= l2; i++) {
            g2.dec(s2[i - l1]);
            g2.inc(s2[i]);
            if (g1 == g2) {
                return true;
            }
        }
        return false;
    }
};
