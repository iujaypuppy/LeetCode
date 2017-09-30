class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator i(nums.begin());
        while(i != nums.end()) {
            if(*i == val) {
                *i = *(nums.end() - 1);
                nums.pop_back();
            } else {
                i++;
            }
        }
        return nums.size();
    }
};
