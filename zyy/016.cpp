class Solution {
  public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        /* initial solution */
        int solution(nums[0] + nums[1] + nums[2]);
        int radius(abs(solution - target));
        for (vector<int>::iterator first = nums.begin(); first != nums.end(); first++) {
                vector<int>::iterator second = first + 1;
                vector<int>::iterator third = nums.end() - 1;
                while (second < third) {
                        int s(*first + *second + *third);
                        int r;
                        if (s < target) {
                                r = target - s;
                                second++;
                        } else {
                                r = s - target;
                                third--;
                        }

                        if (r < radius) {
                                solution = s;
                                radius = r;
                        }
                }
        }
        return solution;
    }
};
