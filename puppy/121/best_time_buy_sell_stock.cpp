class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int max_profit(0);
        vector<int>::iterator buy(prices.begin());
        vector<int>::iterator sell(prices.begin());
        for(vector<int>::iterator i(prices.begin()); i != prices.end(); i++) {
            if (*i > *sell) {
                sell = i; 
            } else if(*i < *buy) {
                max_profit = max(max_profit, (*sell - *buy));
                buy = i;
                sell = i;
            }
        }
        max_profit = max(max_profit, (*sell - *buy));
        return max_profit;
    }
};
