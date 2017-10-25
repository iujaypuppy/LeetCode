class Solution {
  public:
    int PredictMaxScore(vector<int>::iterator begin, vector<int>::iterator end, int sum) {
        if (begin == end) {
            return 0;
        }

        return max(sum - PredictMaxScore(begin + 1, end, sum - *begin),
                   sum - PredictMaxScore(begin, end - 1, sum - *(end - 1)));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum(0);
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            sum += *i;
        }

        int max(PredictMaxScore(nums.begin(), nums.end(), sum));
        return max >= sum - max;
    }
};
