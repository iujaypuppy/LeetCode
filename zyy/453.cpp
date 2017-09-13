class Solution {
  public:
    int minMoves(vector<int>& nums) {
        vector<int>::iterator min(nums.end());
        int sum(0);

        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            if (min == nums.end() || *min > *i) {
                min = i;
            }
            sum += *i;
        }

        return sum - *min * nums.size();
    }
};
