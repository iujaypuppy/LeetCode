class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre = n & 0x01;
        n >>= 1;
        while (n) {
            if ((n & 0x01) == pre) {
                return false;
            }
            pre = n & 0x01;
            n >>= 1;
        }
        return true;
    }
};
