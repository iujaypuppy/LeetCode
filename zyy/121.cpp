class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        /* Maximal prices at point index and afterwards */
        vector<int> maximal(prices.size(), 0);
        int currentMax(0);
        for (int i((int)prices.size() - 1); i >= 0; i--) {
            currentMax = max(currentMax, prices[i]);
            maximal[i] = currentMax;
        }

        int result(0);
        for (size_t i(0); i < prices.size(); i++) {
            result = max(result, maximal[i] - prices[i]);
        }

        return result;
    }
};
