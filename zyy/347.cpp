class Solution {
  public:
    class FreqNum {
      private:
        int freq;
      public:
        int number;
        FreqNum(int n, int f = 1): number(n), freq(f) {}
        inline void add(void) { freq++; }
        inline bool operator<(const FreqNum &other) const {
            return freq > other.freq || (freq == other.freq && number < other.number);
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<FreqNum> freqNums;
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); ++i) {
            if (i == nums.begin() || *i != freqNums.rbegin()->number) {
                freqNums.push_back(FreqNum(*i));
                continue;
            }
            freqNums.rbegin()->add();
        }
        sort(freqNums.begin(), freqNums.end());
        vector<int> ret;
        for (int i(0); i < k; ++i) {
            ret.push_back(freqNums[i].number);
        }
        return ret;
    }
};
