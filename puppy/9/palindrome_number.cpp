class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } 
        // step 1: ten_bits[highest] vs ten_bits[lowest]. Eg.x = (5)434(5)
        // step 2: x = ten_bits[highest - 1] to ten_bits[lowest + 1]. Eg.x = 434
        // step 3: jump to step 1
        int high_bit = high(x);
        int low_bit = 10;
        while (low_bit < high_bit) {
            if ((x / high_bit) != (x % low_bit)) {
                return false;
            }
            x = (x % high_bit) / low_bit;
            high_bit /= 100;
        }
        return (x / high_bit) == (x % low_bit);
    }
    
    int high(int x) {
        int res(1);
        while (x > 9) {
            res *= 10;
            x /= 10;
        }
        return res;
    }
};
