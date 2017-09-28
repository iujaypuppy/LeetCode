class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        string hex("");
        unsigned int n = (unsigned int)num;
        while (n) {
            int mod = (n % 16);
            if (mod < 10) {
                hex += (char)('0' + mod);
            } else {
                hex += (char)('a' + mod - 10);
            }
            n /= 16;
        }
        reverse(hex.begin(), hex.end());
        return hex;
    }
};
