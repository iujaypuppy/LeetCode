class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> positions;
        for (size_t i(0); i < nums.size(); i++) {
            if (positions.find(nums[i]) != positions.end()) {
                if (k + positions[nums[i]] >= i) {
                    return true;
                } else {
                    positions[nums[i]] = i;
                }
            } else {
                positions.insert(pair<int, int>(nums[i], i));
            }
        }
        return false;
    }
};
