class Solution {
  public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid(nums[nums.size() / 2]);
        int moves(0);
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            moves += abs(*i - mid);
        }

        return moves;
    }
};
