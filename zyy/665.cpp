class Solution {
  public:
    bool check(vector<int> &nums) {
        for (vector<int>::iterator i(nums.begin()); i != nums.end() - 1; i++) {
            if (*i > *(i + 1)) {
                return false;
            }
        }
        return true;
    }
    bool checkPossibility(vector<int>& nums) {
        vector<int>::iterator p(nums.end());
        for (vector<int>::iterator i(nums.begin()); i != nums.end() - 1; i++) {
            if (*i > *(i + 1)) {
                p = i;
                break;
            }
        }

        if (p == nums.end()) {
            return true;
        }
        int tmp(*p);
        *p = *(p + 1);
        if (check(nums)) {
            return true;
        }

        // *(p + 1) = *p = tmp;
        *p = tmp;
        *(p + 1) = *p;
        return check(nums);
    }
};
