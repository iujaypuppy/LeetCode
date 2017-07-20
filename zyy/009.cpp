class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int64_t head(1), tail(1), base(10);
        while (head * base <= x) {
            head *= base;
        }

        while (head > tail) {
            if ((x / head) % base != (x / tail) % base) {
                return false;
            }

            head /= 10;
            tail *= 10;
        }

        return true;
    }
};
