class Solution {
  public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current(0), result(0);
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            if (*i == 0) {
                if (current > result) {
                    result = current;
                }
                current = 0;
                continue;
            }

            current++;
        }

        return current > result ? current : result;
    }
};
