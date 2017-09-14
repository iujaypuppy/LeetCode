class Solution {
  public:
    class Gadgets {
      private:
        static const size_t TOTAL = 256;
        int count[TOTAL];
      public:
        Gadgets(const string &str) {
            for (size_t i(0); i < TOTAL; i++) {
                count[i] = 0;
            }

            for (string::const_iterator i(str.begin()); i != str.end(); i++) {
                count[*i]++;
            }
        }
        int longestPalindrome(void) {
            int result(0);
            bool existOdd(false);

            for (size_t i(0); i < TOTAL; i++) {
                result += count[i] & (~(int)1);
                if (count[i] & 1) {
                    existOdd = true;
                }
            }

            return existOdd ? result + 1 : result;
        }
    };
    int longestPalindrome(string s) {
        Gadgets gadgets(s);
        return gadgets.longestPalindrome();
    }
};
