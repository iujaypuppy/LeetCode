class Solution {
  public:
    /* Represent buckets into multidimensional vector and
       use every pig to enumerate every dimension. */
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        /* How far we can go on a single dimension */
        int limit(minutesToTest / minutesToDie + 1), pigs(0);
        while (pow(limit, pigs) < buckets) {
            pigs++;
        }

        return pigs;
    }
};
