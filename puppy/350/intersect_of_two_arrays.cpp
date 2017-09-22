class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int>::iterator i(nums1.begin());
        vector<int>::iterator j(nums2.begin());
        
        vector<int> res;
        while(i != nums1.end() && j != nums2.end()) {
            if (*i == *j) {
                res.push_back(*i);
                i++;
                j++;
            } else if (*i > *j) {
                j++;
            } else {
                i++;
            }
        }
        return res;
    }
};
