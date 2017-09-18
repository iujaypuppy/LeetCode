class Solution {
  public:
    const bool O_N = true;
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        if (O_N) {
            for (vector<int>::iterator i(nums.begin() + 1); i != nums.end(); i++) {
                *i += *(i - 1);
            }

            int min(0), result(*nums.begin());
            for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
                if (*i - min > result) {
                    result = *i - min;
                }

                if (*i < min) {
                    min = *i;
                }
            }

            return result;
        }
        else {
            /* Divide and conquer */
            /* Some ideas: max(leftMax, rightMax, maxCrossLeftRight) */
        }
        return 0;
    }
};
