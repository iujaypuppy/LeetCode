class NumArray {
private:
    vector<int> prefixSums;
public:
    NumArray(vector<int> nums) {
        prefixSums.push_back(0);
        for (size_t i(0); i < nums.size(); i++) {
            prefixSums.push_back(prefixSums[i] + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        if (i < 0 || j > prefixSums.size() - 2) {
            return 0;
        }
        return prefixSums[j + 1] - prefixSums[i];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
