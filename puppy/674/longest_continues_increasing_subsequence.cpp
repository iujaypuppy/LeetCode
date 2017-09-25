class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int longest(0);
        vector<int>::iterator j(nums.begin());
        vector<int>::iterator i(nums.begin() + 1);
        while (i != nums.end()) {
            if ( *i <= *(i - 1)) {
                longest = max(longest, (int)(i - j));
                j = i;
            }
            i++;
        }
        longest = max(longest, (int)(i - j));
        return longest;
    }
};
