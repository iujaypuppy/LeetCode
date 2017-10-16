class Solution {
  public:
    int findShortestSubArray(vector<int>& nums) {
        static const int MAX_NUMBER(50000);
        vector<int> freq(MAX_NUMBER, 0);
        int degree(0);
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); ++i) {
            freq[*i]++;
            degree = max(degree, freq[*i]);
        }

        int ret(nums.size());
        for (size_t i(0); i < freq.size(); ++i) {
            if (freq[i] != degree) {
                continue;
            }

            size_t begin, end;
            for (vector<int>::iterator j(nums.begin()); j != nums.end(); ++j) {
                if (i == *j) {
                    begin = j - nums.begin();
                    break;
                }
            }

            for (vector<int>::reverse_iterator j(nums.rbegin()); j != nums.rend(); ++j) {
                if (i == *j) {
                    end = nums.rend() - j - 1;
                    break;
                }
            }

            ret = min((int)end - (int)begin + 1, ret);
        }
        

        return ret;
    }
};
