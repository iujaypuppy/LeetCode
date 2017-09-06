class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.size() == 0) {
            return nums;
        }
        int originalR(nums.size()), originalC(nums[0].size());
        if (r * c != originalR * originalC) {
            return nums;
        }

        vector<vector<int>> result;
        int count(0);
        vector<int> *current;
        for (vector<vector<int>>::iterator row(nums.begin()); row != nums.end(); row++) {
            for (vector<int>::iterator col(row->begin()); col != row->end(); col++) {
                if (count == 0) {
                    result.push_back(vector<int>());
                    current = &*(result.end() - 1);
                }
                current->push_back(*col);
                count++;
                if (count == c) {
                    count = 0;
                }
            }
        }
        return result;
    }
};
