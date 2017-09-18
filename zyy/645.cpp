class Solution {
  public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> result;
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            if (i != nums.begin() && abs(*i) == abs(*(i - 1))) {
                result.push_back(abs(*i));
            }

            /* Learned from Puppy! */
            int &indicator(*(nums.begin() + abs(*i) - 1));
            if (indicator > 0) {
                indicator = -indicator;
            }
        }

        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            if (*i > 0) {
                result.push_back((int)(i - nums.begin() + 1));
            }
        }

        return result;
    }
};
