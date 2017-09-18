class Solution {
  public:
    bool isPerfectSquare(int num) {
        int left(0), right(num + 1);
        while (left < right) {
            int mid((left + right) / 2);
            if (mid == left || mid == right) {
                break;
            }

            int64_t sqr((int64_t)mid * mid);
            if (sqr == num) {
                return true;
            }

            if (sqr < num) {
                left = mid;
            } else {
                right = mid;
            }
        }

        return false;
    }
};
