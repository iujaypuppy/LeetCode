class Solution {
  public:
    string toHex(int num) {
        string result;
        unsigned int n(num);
        const char *digits[] =
                { "0", "1", "2", "3", "4", "5", "6", "7",
                  "8", "9", "a", "b", "c", "d", "e", "f", };
        while (n > 0) {
            result = digits[n % 16] + result;
            n /= 16;
        }

        return result == "" ? "0" : result;
    }
};
