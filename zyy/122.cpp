class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int sum(0);
        for (vector<int>::iterator i(prices.begin() + 1);
             i != prices.end(); i++) {
            int diff(*i - *(i - 1));
            if (diff > 0) {
                sum += diff;
            }
        }

        return sum;
    }
};
