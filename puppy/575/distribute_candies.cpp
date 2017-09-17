class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        sort(candies.begin(), candies.end());
        int sum_kinds = 0;
        for (int i = 0; i < candies.size(); i++) {
            if (i == 0 || candies[i] != candies[i-1]) {
                sum_kinds++;
            }
        }
        return (sum_kinds > (candies.size() >> 1)) ? (candies.size() >> 1) : sum_kinds;
    }
};
