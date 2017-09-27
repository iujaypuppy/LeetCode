class Solution {
  public:
    string optimalDivision(vector<int>::iterator begin, vector<int>::iterator end, bool max,
                           double &val) {
        if (begin + 1 == end) {
            val = *begin;
            return to_string(*begin);
        }
        if (begin + 2 == end) {
            val = (double)*begin / *(begin + 1);
            return to_string(*begin) + "/" + to_string(*(begin + 1));
        }
        string ret;
        for (vector<int>::iterator i(begin); i < end - 1; i++) {
            double firstVal, secondVal;
            string first, second;
            if (max) {
                first = optimalDivision(begin, i + 1, true, firstVal);
                second = optimalDivision(i + 1, end, false, secondVal);
                if (ret.empty() || firstVal / secondVal > val) {
                    val = firstVal / secondVal;
                    if (second.find('/') == string::npos) {
                        ret = first + "/" + second;
                    } else {
                        ret = first + "/(" + second + ")";
                    }
                }
            } else {
                first = optimalDivision(begin, i + 1, false, firstVal);
                second = optimalDivision(i + 1, end, true, secondVal);
                if (ret.empty() || firstVal / secondVal < val) {
                    val = firstVal / secondVal;
                    if (second.find('/') == string::npos) {
                        ret = first + "/" + second;
                    } else {
                        ret = first + "/(" + second + ")";
                    }
                }
            }
        }
        return ret;
    }
    string optimalDivision(vector<int>& nums) {
        double val;
        return optimalDivision(nums.begin(), nums.end(), true, val);
    }
};
