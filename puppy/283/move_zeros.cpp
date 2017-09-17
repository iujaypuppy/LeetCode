class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros_num = 0;
        for (vector<int>::iterator iter(nums.begin()); iter != nums.end(); iter++) {
            if (!(*iter)) {
                zeros_num++;
                continue;
            }
            *(iter - zeros_num) = *iter;
        }
        for (vector<int>::iterator iter(nums.end() - zeros_num); iter != nums.end(); iter++) {
            *iter = 0;
        }
    }
};
