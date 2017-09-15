class Solution {
  public:
    int digitSquareSum(int n) {
        int result(0);
        while (n > 0) {
            int digit(n % 10);
            n /= 10;
            result += digit * digit;
        }

        return result;
    }

    /*
      Simple algorithm to check cycle: One person go along the cycle
        at the speed of one step at a period of time, another person
        go along the cycle at the speed of two steps at the same
        period time. Before the slower one finish his first cycle, the
        faster one will catch the slower one.
    */
    bool isHappy(int n) {
        int one(n), two(n);
        do {
            one = digitSquareSum(one);
            two = digitSquareSum(digitSquareSum(two));
        } while (one != two);

        return one == 1;
    }
};
