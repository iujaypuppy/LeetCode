class Solution {
  public:
    int majorityElement(vector<int>& nums) {
        int counter(0), who;
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            if (counter == 0) {
                who = *i;
            }
            if (*i == who) {
                counter++;
            } else {
                counter--;
            }
        }
        return who;
    }
};
