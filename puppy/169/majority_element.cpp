class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate(0), count(0);
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            if (!count) {
                candidate = *i;
                count++;
                continue;
            }
            if (*i == candidate) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
};
