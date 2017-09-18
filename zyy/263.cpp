class Solution {
  public:
    int divideToDeath(int num, int prime) {
        if (num == 0) {
            return 0;
        }
        while (num % prime == 0) {
            num /= prime;
        }

        return num;
    }
    bool isUgly(int num) {
        num = divideToDeath(num, 2);
        num = divideToDeath(num, 3);
        num = divideToDeath(num, 5);

        return num == 1;
    }
};
