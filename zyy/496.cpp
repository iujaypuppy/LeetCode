class Solution {
  public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> result;
        for (vector<int>::iterator i(findNums.begin()); i != findNums.end(); i++) {
            vector<int>::iterator j;
            for (j = nums.begin(); j != nums.end(); j++) {
                if (*i == *j) {
                    break;
                }
            }

            for (j = j + 1; j != nums.end(); j++) {
                if (*j > *i) {
                    result.push_back(*j);
                    break;
                }
            }

            if (j == nums.end()) {
                result.push_back(-1);
            }
        }
        return result;
    }
};
