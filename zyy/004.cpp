class Solution {
  public:
    class MergedArray {
      private:
        vector<int> array;
      public:
        MergedArray(vector<int>& nums1, vector<int>& nums2) {
            vector<int>::iterator i1, i2;
            for (i1 = nums1.begin(), i2 = nums2.begin();
                 i1 != nums1.end() && i2 != nums2.end();
                 /* empty */) {
                if (*i1 < *i2) {
                    array.push_back(*(i1++));
                } else {
                    array.push_back(*(i2++));
                }
            }

            /*
              There must be at least one iterator of i1 and i2 being end,
              so insert them directly without checking.
            */
            array.insert(array.end(), i1, nums1.end());
            array.insert(array.end(), i2, nums2.end());
        }

        double median(void) const {
            if (array.size() % 2 == 1) {
                return array[array.size() / 2];
            }

            return ((double)array[array.size() / 2] + (double)array[array.size() / 2 - 1]) / 2;
        }
    };
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        MergedArray arr(nums1, nums2);
        return arr.median();
    }
};

