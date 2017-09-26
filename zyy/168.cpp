class Solution {
  public:
    string convertToTitle(int n) {
        static const int BASE(26);
        string ret;
        while (n > 0) {
            int digit(n % BASE == 0 ? BASE : n % BASE);
            ret = string(1, 'A' + digit - 1) + ret;
            n -= digit;
            n /= BASE;
        }

        return ret;
    }
};
