class Solution {
  public:
    void reverse(vector<int>::iterator begin, vector<int>::iterator end) {
        while (begin < end) {
            int tmp(*begin);
            *begin = *end;
            *end = tmp;
            begin++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) {
            return;
        }
        int n((int)nums.size());
        k %= n;

        reverse(nums.begin(), nums.begin() + n - k - 1);
        reverse(nums.begin() + n - k, nums.end() - 1);
        reverse(nums.begin(), nums.end() - 1);
    }
};
