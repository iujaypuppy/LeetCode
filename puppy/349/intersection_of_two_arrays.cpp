class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, bool> nums_status;
        for (vector<int>::iterator iter(nums1.begin()); iter != nums1.end(); iter++) {
            if (nums_status.find(*iter) == nums_status.end()) {
                nums_status.insert(pair<int, bool>(*iter, true));
            }
        }
        vector<int> res;
        for (vector<int>::iterator iter(nums2.begin()); iter != nums2.end(); iter++) {
            if (nums_status.find(*iter) != nums_status.end() && nums_status[*iter]) {
                res.push_back(*iter);
                nums_status[*iter] = false;
            }
        }
        return res;
    }
};
