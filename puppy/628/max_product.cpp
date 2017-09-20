class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>::iterator begin(nums.begin());
        vector<int>::iterator end(nums.end());
        int a = (*begin) * (*(begin + 1)) * (*(end - 1));
        int b = (*(end - 1)) * (*(end - 2)) * (*(end - 3));
        return max(a, b);
    }
};
