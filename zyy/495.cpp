class Solution {
  public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ret(0);
        for (vector<int>::iterator i(timeSeries.begin());
             i != timeSeries.end(); ++i) {
            int start(*i), end(*i + duration - 1);
            while (i + 1 != timeSeries.end() && *(i + 1) <= end) {
                ++i;
                end = (*i + duration - 1);
            }
            ret += end - start + 1;
        }

        return ret;
    }
};
