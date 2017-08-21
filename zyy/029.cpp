class Solution {
  public:
    int divide(int dividend, int divisor) {
        /*
          Only one situation to overflow:
          dividend = MIN_INT, divisor = -1
         */
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        bool negative(false);
        int64_t absDividend(dividend), absDivisor(divisor);
        if (dividend < 0) {
            absDividend = -(int64_t)dividend;
            negative = !negative;
        }

        if (divisor < 0) {
            absDivisor = -(int64_t)divisor;
            negative = !negative;
        }

        int64_t total(absDivisor), times(1), lastTotal(0), lastTimes(0);
        while (total <= absDividend) {
            lastTotal = total;
            lastTimes = times;
            total += total;
            times += times;
        }

        if (lastTimes > 0) {
            lastTimes += divide(absDividend - lastTotal, absDivisor);
        }

        return negative ? -lastTimes : lastTimes;
    }
};
