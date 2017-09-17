class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            res += (*i - *(nums.begin()));
        }
        return res;
    }
};
