class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i(0); i < m; i++) {
            nums1[m + n - 1 - i] = nums1[m - 1 - i];
        }
        
        int i(n), j(0), count(0);
        while (count < (m + n)) {
            if (i >= (m + n)) {
                nums1[count] = nums2[j];
                j++;
            } else if(j >= n) {
                nums1[count] = nums1[i];
                i++;
            } else if (nums1[i] <= nums2[j]) {
                nums1[count] = nums1[i];
                i++;
            } else {
                nums1[count] = nums2[j];
                j++;
            }
            count++;
        }
    }
};
