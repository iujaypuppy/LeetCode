class Solution {
  public:
    int singleNumber(vector<int>& nums) {
        int result(0);
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            result ^= *i;
        }

        return result;
    }
};
