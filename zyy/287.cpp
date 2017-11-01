class Solution {
  public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) {
            return -1;
        }
        int slow(nums.size()), fast(nums.size());
        do {
            slow = nums[slow - 1];
            fast = nums[nums[fast - 1] - 1];
        } while (slow != fast);

        fast = nums.size();
        while (fast != slow) {
            slow = nums[slow - 1];
            fast = nums[fast - 1];
        }

        return slow;
    }
};
