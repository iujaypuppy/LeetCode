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
        /* isIntersect operator */
        bool operator&(const Gadgets &other) const {
            for (size_t i(0); i < TOTAL; i++) {
                if (count[i] != 0 && other.count[i] != 0) {
                    return true;
                }
            }

            return false;
        }
    };
    int maxProduct(vector<string>& words) {
        vector<Gadgets> gadgets;
        for (vector<string>::iterator i(words.begin()); i != words.end(); i++) {
            gadgets.push_back(Gadgets(*i));
        }

        int ret(0);
        for (size_t i(0); i != gadgets.size(); i++) {
            for (size_t j(i + 1); j != gadgets.size(); j++) {
                if (gadgets[i] & gadgets[j]) {
                    continue;
                }
                ret = max(ret, (int)(words[i].length() * words[j].length()));
            }
        }

        return ret;
    }
};
