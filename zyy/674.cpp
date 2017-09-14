class Solution {
  public:
    int findLengthOfLCIS(vector<int> &nums) {
        int max(0), count(0), last;
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            if (count == 0 || *i > last) {
                count++;
            } else {
                count = 1;
            }
            last = *i;
            if (count > max) {
                max = count;
            }
        }
        return max;
    }
};
