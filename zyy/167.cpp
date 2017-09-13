class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> indices;
        vector<int>::iterator left(numbers.begin()), right(numbers.end() - 1);
        while (left < right) {
            int sum(*left + *right);
            if (sum > target) {
                right--;
                continue;
            }
            if (sum < target) {
                left++;
                continue;
            }

            indices.push_back(left - numbers.begin() + 1);
            indices.push_back(right - numbers.begin() + 1);
            return indices;
        }

        return indices;
    }
};
