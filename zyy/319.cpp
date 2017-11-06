class Solution {
  public:
#define O_NLOGN 0
#if O_NLOGN
    void generatePrimeList(vector<int> &primes, int n) {
        /* Generate prime list */
        int primeLimit(sqrt(n) + 1);
        bool *isPrime = new bool[primeLimit];
        for (int i(0); i < primeLimit; i++) {
            isPrime[i] = true;
        }
        for (int i(2); i < primeLimit; i++) {
            if (!isPrime[i]) {
                continue;
            }
            primes.push_back(i);
            int val(i + i);
            while (val < primeLimit) {
                isPrime[val] = false;
                val += i;
            }
        }
        delete [] isPrime;
    }
    int countFactor(int &n, int f) {
        int ret(0);
        while (n % f == 0) {
            n /= f;
            ret++;
        }
        return ret;
    }
    int factors(vector<int> &list, int n) {
        /* Prime factorization */
        int ret(1);
        size_t size(list.size());
        for (size_t i(0); i != size && n >= list[i]; i++) {
            if (n % list[i] != 0) {
                continue;
            }

            ret *= (1 + countFactor(n, list[i]));
        }
        if (n != 1) {
            /* The rest of this number must be a prime */
            ret *= 2;
        }
        return ret;
    }
#endif
    int bulbSwitch(int n) {
#if O_NLOGN
        int ret(0);
        vector<int> primes;
        generatePrimeList(primes, n);
        for (int i(1); i <= n; i++) {
            if (factors(primes, i) % 2 == 1) {
                ret++;
            }
        }
        return ret;
#else
        return sqrt(n);
#endif
    }
};
