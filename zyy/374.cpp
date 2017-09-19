// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
  public:
    int guessNumber(int n) {
        int64_t low(1), high(n);
        while (low <= high) {
            int64_t mid = (low + high) / 2;
            int ret(guess((int)mid));
            if (ret == 0) {
                return (int)mid;
            }

            if (ret == -1) {
                /* mid is high */
                high = mid - 1;
                continue;
            }

            low =  mid + 1;
        }

        return 0;
    }
};
