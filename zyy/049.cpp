class Solution {
  public:
    class Gadgets {
      private:
        static const size_t TOTAL = 26;
        int count[TOTAL];
        string s;
      public:
        string toString(void) const { return s; }
        Gadgets(const string &str = ""): s(str) {
            for (size_t i(0); i < TOTAL; i++) {
                count[i] = 0;
            }

            for (string::const_iterator i(str.begin()); i != str.end(); i++) {
                count[(unsigned char)*i - 'a']++;
            }
        }
        bool operator<(const Gadgets &other) const {
            for (size_t i(0); i < TOTAL; i++) {
                if (count[i] < other.count[i]) {
                    return true;
                }
                if (count[i] > other.count[i]) {
                    return false;
                }
            }
            return false;
        }
        bool operator==(const Gadgets &other) const {
            for (size_t i(0); i < TOTAL; i++) {
                if (count[i] != other.count[i]) {
                    return false;
                }
            }
            return true;
        }
        bool operator!=(const Gadgets &other) const { return !(*this == other); }
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<Gadgets> gadgets;
        for (vector<string>::iterator i(strs.begin()); i != strs.end(); i++) {
            gadgets.push_back(Gadgets(*i));
        }
        sort(gadgets.begin(), gadgets.end());
        vector<vector<string>> ret;
        for (vector<Gadgets>::iterator i(gadgets.begin()); i != gadgets.end(); i++) {
            if (i == gadgets.begin() || *i != *(i - 1)) {
                ret.push_back(vector<string>(0));
            }
            ret.rbegin()->push_back(i->toString());
        }
        return ret;
    }
};
