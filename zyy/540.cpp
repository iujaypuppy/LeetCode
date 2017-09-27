class Solution {
  public:
    int singleNonDuplicate(vector<int>& nums) {
        int sum(0);
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            sum ^= *i;
        }

        return sum;
    }
};
