class Solution {
public:
    bool isPerfectSquare(int num) {
        int64_t i(1), j(half_bits(num));
        if (j * j < num) {
            return false;
        }
        while (i < j - 1) {
            int64_t mid = ((j + i) / 2);
            if (mid * mid > num) {
                j = mid;
            } else if (mid * mid < num) {
                i = mid;
            } else {
                return true;
            }
        }
        return (i * i == num) || (j * j == num);
    }
    
    int64_t half_bits(int num) {
        int64_t res(0), count(1);
        while (num) {
            res += 9 * count;
            num /= 100;
            count *= 10;
        }
        return res;
    }
};
