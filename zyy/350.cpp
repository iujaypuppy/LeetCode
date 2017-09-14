class Solution {
  public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int>::iterator i1(nums1.begin()), i2(nums2.begin());
        vector<int> result;
        while (i1 != nums1.end() && i2 != nums2.end()) {
            if (*i1 == *i2) {
                result.push_back(*i1);
                i1++;
                i2++;
                continue;
            }

            if (*i1 > *i2) {
                i2++;
                continue;
            }

            i1++;
        }
        return result;
    }
};
