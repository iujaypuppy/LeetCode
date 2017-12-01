class Solution {
  public:
    class Gadgets {
      private:
        static const size_t TOTAL = 10;
        int count[TOTAL];
      public:
        Gadgets(const string &str) {
            for (size_t i(0); i < TOTAL; i++) {
                count[i] = 0;
            }

            for (string::const_iterator i(str.begin()); i != str.end(); i++) {
                if (*i >= '0' && *i <= '9') {
                    count[*i - '0']++;
                }
            }
        }
        int operator&(const Gadgets &other) {
            int ret(0);
            for (int i(0); i <= 9; i++) {
                ret += min(count[i], other.count[i]);
            }
            return ret;
        }
    };
    string getHint(string secret, string guess) {
        int bull(0);
        for (size_t i(0); i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bull++;
                secret[i] = guess[i] = '-';
            }
        }
        int cow(Gadgets(secret) & Gadgets(guess));
        return string(to_string(bull)) + "A" + to_string(cow) + "B";
    }
};
