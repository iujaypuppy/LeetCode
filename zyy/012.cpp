class Solution {
  public:
    class RomanDigit {
      private:
        const string one, five, ten;
      public:
        const int weight;
        RomanDigit(const string &o, const string &f, const string &t, const int &w):
                one(o), five(f), ten(t), weight(w) {}
        /*
         *digit* means the digit on the position of *weight*.
         e.g.: if weight is 10, the number is 987, this digit
         should be 8, and the output of this function is LXXX
         */
        const string toRoman(int digit) {
            if (digit < 4) {
                string ret;
                for (int i = 0; i < digit; i++) {
                    ret += one;
                }
                return ret;
            }

            if (digit == 4) {
                return one + five;
            }

            if (digit < 9) {
                string ret(five);
                for (int i = 5; i < digit; i++) {
                    ret += one;
                }
                return ret;
            }

            if (digit == 9) {
                return one + ten;
            }
            return "";
        }
    };

    string intToRoman(int num) {
        vector<RomanDigit> digits;
        digits.push_back(RomanDigit("M", "M", "M", 1000));
        digits.push_back(RomanDigit("C", "D", "M", 100));
        digits.push_back(RomanDigit("X", "L", "C", 10));
        digits.push_back(RomanDigit("I", "V", "X", 1));

        string ret;
        for (vector<RomanDigit>::iterator i = digits.begin();
             i != digits.end(); i++) {
            ret += i->toRoman((num / i->weight) % 10);
        }

        return ret;
    }
};
