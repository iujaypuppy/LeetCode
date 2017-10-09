class Solution {
  public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorSum(0);
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            xorSum ^= *i;
        }

        /*
          This is the bit where two numbers differ, so we can divide
          the whole vector into two parts by this bit.
         */
        int bitDiff(xorSum & -xorSum);
        vector<int> ret(2, 0);
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            if ((*i & bitDiff) == 0) {
                ret[0] ^= *i;
                continue;
            }
            ret[1] ^= *i;
        }

        return ret;
    }
};
