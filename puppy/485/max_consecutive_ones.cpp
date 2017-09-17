class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        bool start_count = false;
        vector<int>:: iterator i;
        for (vector<int>::iterator j = nums.begin(); j <= nums.end(); j++) {
            if (*j == 1 && !start_count) {
                i = j;
                start_count = true;
            } 
            if ((*j == 0 && start_count) || (j == nums.end() && start_count)) {
                if ( j - i > res) {
                    res = j - i;
                }
                start_count = false;
            }
        }
        return res;
    }
};
