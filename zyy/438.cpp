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
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) {
            return vector<int>();
        }


        Gadgets pFrags(p), sFrags;
        vector<int> ret;

        for (size_t i(0); i < s.size() && i < p.size(); i++) {
            sFrags.inc(s[i]);
        }

        for (size_t i(0); i + p.size() <= s.size(); i++) {
            if (i != 0) {
                sFrags.dec(s[i - 1]);
                sFrags.inc(s[i + p.size() - 1]);
            }
            if (sFrags == pFrags) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
