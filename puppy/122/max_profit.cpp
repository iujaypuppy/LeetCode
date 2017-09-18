class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        vector<int>::iterator buy(prices.end());
        for (vector<int>::iterator i(prices.begin()); i != prices.end(); i++) {
            if ((i == prices.begin()) && (*i <= *(i + 1))) {
                buy = i;
            } else if((i == prices.end() - 1) && (*i >= *(i - 1))) {
                 if (buy != prices.end()) {
                    profit += (*i - *buy);
                    buy = prices.end();
                }
            } else if((*i >= *(i + 1)) && (*i >= *(i - 1))) {
                if (buy != prices.end()) {
                    profit += (*i - *buy);
                    buy = prices.end();
                }
            } else if((*i <= *(i + 1)) && (*i <= *(i - 1))) {
                buy = i;
            }
        }
        return profit;
    }
};
