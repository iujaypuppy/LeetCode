class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t len = nums.size();
        if (len == 0) {
            return len;
        }
        
        int i(0), j(1);
        for (; j < len; j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        
        len = i + 1;
        nums.erase(nums.begin() + len, nums.end());
        return len;
    }
};
