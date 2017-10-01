class Solution {
public:
    int trailingZeroes(int n) {
        int sum(0);
        int64_t step = 5;
        while (step <= (int64_t)n) {
            sum += n / step;
            step *= 5;
        }
        return sum;
    }
};
