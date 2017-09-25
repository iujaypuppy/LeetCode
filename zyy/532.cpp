class Solution {
  public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        if (k < 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        vector<int>::iterator second(nums.begin()), last(nums.end());
        int ret(0);
        for (vector<int>::iterator first(nums.begin()); first != nums.end(); first++) {
            if (last != nums.end() && *first == *last) {
                continue;
            }
            last = first;

            while (second != nums.end() && (*second < *first + k || second == first)) {
                second++;
            }

            if (*first + k == *second) {
                ret++;
            }
        }
        return ret;
    }
};
