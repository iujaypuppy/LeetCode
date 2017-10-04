class Solution {
public:
    bool judgeSquareSum(int c) {
        return isSquareSum(0, c);
    }
    
    bool isSquareSum(int64_t a, int64_t c) {
        if (a * a > c) {
            return false;
        }
        size_t b = sqrt(c - a * a);
        if (b * b + a * a == c) {
            return true;
        }
        return isSquareSum(a + 1, c);
    }
};
