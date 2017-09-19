class Solution {
  public:
    class Factorization {
      private:
        int num;
        class Prime {
          public:
            int prime;
            int count;
            int used;
            Prime(int p = 0): prime(p), count(0), used(0) {}
        };
        vector<Prime> primes;
      public:
        Factorization(int n): num(n) {
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
                primes.push_back(Prime(i));
                int val(i + i);
                while (val < primeLimit) {
                    isPrime[val] = false;
                    val += i;
                }
            }
            delete [] isPrime;

            /* Prime factorization */
            for (vector<Prime>::iterator i(primes.begin()); i != primes.end(); i++) {
                while (n % i->prime == 0) {
                    n /= i->prime;
                    i->count++;
                }
            }
            if (n != 1) {
                /* The rest of this number must be a prime */
                primes.push_back(Prime(n));
                primes.rbegin()->count++;
            }
        }

      private:
        static int power(int base, int times) inline {
            if (times == 0) {
                return 1;
            }
            return (times % 2 == 0 ? 1 : base) *
                    power(base * base, times / 2);
        }
        int factor(void) const {
            int ret(1);
            for (vector<Prime>::const_iterator i(primes.begin()); i != primes.end(); i++) {
                ret *= power(i->prime, i->used);
            }

            return ret;
        }
        /* Use DFS to enumerate all factors */
        int factorSumRecursive(vector<Prime>::iterator i) {
            if (i == primes.end()) {
                return factor();
            }

            int ret(0);
            for (int j(0); j <= i->count; j++) {
                i->used = j;
                ret += factorSumRecursive(i + 1);
            }
            i->used = 0;

            return ret;
        }
      public:
        int factorSum(void) {
            return factorSumRecursive(primes.begin());
        }
    };

    bool checkPerfectNumber(int num) {
        Factorization factors(num);
        return factors.factorSum() == num;
    }
};
