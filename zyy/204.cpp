class Solution {
  public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        int ret(0);
        for (int i(2); i < n; i++) {
            if (!isPrime[i]) {
                continue;
            }

            ret++;
            for (int j(i + i); j < n; j += i) {
                isPrime[j] = false;
            }
        }

        return ret;
    }
};
