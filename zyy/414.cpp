class Solution {
  public:
    int thirdMax(vector<int>& nums) {
        vector<int>::iterator first(nums.end()), second(nums.end()), third(nums.end());

        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            if (first == nums.end() || *i > *first) {
                third = second;
                second = first;
                first = i;
                continue;
            } else if (first != nums.end() && *i == *first) {
                continue;
            }

            if (second == nums.end() || *i > *second) {
                third = second;
                second = i;
                continue;
            } else if (second != nums.end() && *i == *second) {
                continue;
            }

            if (third == nums.end() || *i > *third) {
                third = i;
            }
        }

        return third == nums.end() ? *first : *third;
    }
};
