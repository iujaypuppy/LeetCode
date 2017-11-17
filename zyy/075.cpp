class Solution {
  public:
    void sortColors(vector<int>& nums) {
        vector<int> counters(3, 0);
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            counters[*i]++;
        }
        int p(0);
        for (int i(0); i < (int)counters.size(); i++) {
            for (int j(0); j < counters[i]; j++) {
                nums[p++] = i;
            }
        }
    }
};
