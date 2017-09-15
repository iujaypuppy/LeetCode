class Solution {
  public:
    class mergedElement {
      public:
        int value;
        size_t count;
        mergedElement(const int &v, const size_t &c):
                value(v), count(c) {}
    };
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>::iterator last(nums.begin());
        vector<mergedElement> numbers;
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            if (*i != *last) {
                numbers.push_back(mergedElement(*last, i - last));
                last = i;
            }
        }
        if (last != nums.end()) {
            numbers.push_back(mergedElement(*last, nums.end() - last));
        }

        int result(0);
        for (vector<mergedElement>::iterator i(numbers.begin()); i != numbers.end(); i++) {
            if (i + 1 == numbers.end()) {
                continue;
            }

            if (i->value + 1 == (i + 1)->value) {
                result = max(result, (int)(i->count + (i + 1)->count));
            }
        }

        return result;
    }
};
