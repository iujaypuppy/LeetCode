class Solution {
  public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        static const int BASE = 7;
        bool negative(num < 0);
        if (num < 0) {
            num = -num;
        }

        string result;
        while (num > 0) {
            result = to_string(num % BASE) + result;
            num /= BASE;
        }

        return negative ? "-" + result : result;
    }
};
