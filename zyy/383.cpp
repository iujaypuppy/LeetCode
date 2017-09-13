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

        bool operator<(const Gadgets &other) const {
            for (size_t i(0); i < TOTAL; i++) {
                if (count[i] > other.count[i]) {
                    return false;
                }
            }

            return true;
        }
    };
    bool canConstruct(string ransomNote, string magazine) {
        Gadgets ransom(ransomNote), mag(magazine);
        return ransom < mag;
    }
};
