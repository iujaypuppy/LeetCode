class NumArray {
  public:
    /* sumPrefix[i] represents the sum of [0, i] */
    vector<int> sumPrefix;
    NumArray(vector<int> nums) {
        int sum(0);
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            sum += *i;
            sumPrefix.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        return i == 0 ? sumPrefix[j] : sumPrefix[j] - sumPrefix[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j); 
 */
