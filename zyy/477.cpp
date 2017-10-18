class Solution {
  public:
    int totalHammingDistance(vector<int>& nums) {
        int sum(0);
        for (int i(0); i < 32; ++i) {
            int mask(1 << i), zeros(0), ones(0);
            for (vector<int>::iterator i(nums.begin()); i != nums.end(); ++i) {
                if (((*i) & mask) == 0) {
                    ++zeros;
                    continue;
                }
                ++ones;
            }
            sum += ones * zeros;
        }

        return sum;
    }
};
