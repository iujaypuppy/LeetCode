class Solution {
  public:
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator zero(nums.begin()), valid;
        while (zero < nums.end()) {
            while (zero < nums.end() && *zero != 0) {
                zero++;
            }

            if (zero == nums.end()) {
                continue;
            }

            valid = zero + 1;
            while (valid < nums.end() && *valid == 0) {
                valid++;
            }

            if (valid == nums.end()) {
                break;
            }

            *zero = *valid;
            *valid = 0;
            zero++;
        }
    }
};
