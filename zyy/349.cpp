class Solution {
  public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        vector<int>::iterator i1(nums1.begin()), i2(nums2.begin());
        while (i1 != nums1.end() && i2 != nums2.end()) {
            while (i1 != nums1.begin() && i1 != nums1.end() && *i1 == *(i1 - 1)) {
                i1++;
            }

            if (i1 == nums1.end()) {
                break;
            }

            while (i2 != nums2.end() && *i2 < *i1) {
                i2++;
            }

            if (i2 == nums2.end()) {
                break;
            }

            if (*i1 == *i2) {
                result.push_back(*i1);
            }
            i1++;
        }

        return result;
    }
};
