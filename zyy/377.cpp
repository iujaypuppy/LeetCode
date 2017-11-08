class Solution {
  public:
    int combinationSum4(vector<int> &nums, int target, map<int, int> &mem) {
        map<int, int>::iterator i = mem.find(target);
        if (i != mem.end()) {
            return i->second;
        }
        if (target == 0) {
            mem[target] = 1;
            return 1;
        }

        mem[target] = 0;
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            if (target >= *i) {
                mem[target] += combinationSum4(nums, target - *i, mem);
            }
        }

        return mem[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        map<int, int> mem;
        return combinationSum4(nums, target, mem);
    }
};
