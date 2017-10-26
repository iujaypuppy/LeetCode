class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) {
            return 0;
        }
        vector<bool> primes(n, true);
        int count(0);
        for (int i(2); i < n; i++) {
            if (primes[i]) {
                count++;
                setPrimes(primes, n, i);
            }
        }
        return count;
    }
    
    void setPrimes(vector<bool>& primes, int64_t n, int64_t prime) {
        int64_t i = prime;
        while ((i * prime) < n) {
            primes[i * prime] = false;
            i++;
        }
    }
};

