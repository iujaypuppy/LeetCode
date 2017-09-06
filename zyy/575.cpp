class Solution {
  public:
    int distributeCandies(vector<int>& candies) {
        sort(candies.begin(), candies.end());
        int types(0), lastType;
        for (vector<int>::iterator i = candies.begin(); i != candies.end(); i++) {
            if (types == 0 || *i != lastType) {
                types++;
                lastType = *i;
            }
        }

        return candies.size() / 2 < types ? candies.size() / 2 : types;
    }
};
