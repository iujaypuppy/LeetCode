class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
        for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++) {
            int value = *i;
            vector<int>::iterator j;
            for (j = i + 1; j != nums.end() && *j == value; j++) {}
            nums.erase(i + 1, j);
        }
        return nums.size();
    }
};
