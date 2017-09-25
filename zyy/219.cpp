class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> window;
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            if (window.find(*i) != window.end()) {
                window.insert(pair<int, int>(*i, 0));
            }
            window[*i]++;

            if (i - nums.begin() >= k + 1) {
                window[*(i - k - 1)]--;
            }

            if (window[*i] > 1) {
                return true;
            }
        }

        return false;
    }
};
