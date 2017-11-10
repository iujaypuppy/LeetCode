class Solution {
  public:
    int triangleNumber(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ret(0);
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            vector<int>::iterator k(i + 1);
            for (vector<int>::iterator j(i + 1); j != nums.end(); j++) {
                int two(*i + *j);
                while (k != nums.end() && two > *k) {
                    k++;
                }
                if (k - 1 >= j) {
                    ret += k - 1 - j;
                }
            }
        }

        return ret;
    }
};
