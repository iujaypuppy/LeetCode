class Solution {
  public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }

        vector<int>::iterator begin(A.end());
        int gap, result(0);
        for (vector<int>::iterator i(A.begin()); i != A.end(); ++i) {
            if (begin == A.end()) {
                begin = i;
                continue;
            }
            if (i == begin + 1) {
                gap = *i - *begin;
                continue;
            }
            if (*i - *(i - 1) != gap || i == A.end() - 1) {
                /* The length of longest slice with the same gap. */
                int length(*i - *(i - 1) != gap ? i - begin : A.end() - begin);
                /*
                  Total number of slices can be calculated.
                  e.g.: the length longest slice is 5, then there will be
                  three 3-length slices, two 4-length slices and one 5-length.
                  So in total there will be 3 + 2 + 1 = 6 slices.
                 */
                int numberOfShortestSlices(length - 3 + 1);
                result += (numberOfShortestSlices + 1) * numberOfShortestSlices / 2;
                if (i != A.end() - 1) {
                    begin = i - 1;
                    gap = *i - *begin;
                }
            }
        }

        return result;
    }
};
