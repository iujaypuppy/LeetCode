class Solution {
  public:
    int myAtoi(string str) {
        string::iterator begin(str.begin()), end;

        /* remove heading spaces */
        while (begin != str.end() && isspace(*begin)) {
            begin++;
        }
        /* find valid integer range */
        end = begin;
        if (end != str.end() && (*end == '+' || *end == '-')) {
            end++;
        }
        while (end != str.end() && isdigit(*end)) {
            end++;
        }
        /* transfer into integer */
        int ret = 0;
        bool overflowed(false);
        if (begin < end) {
            int sign = *begin == '-' ? -1 : 1;
            if (!isdigit(*begin)) {
                begin++;
            }

            while (begin < end) {
                int digit = *begin - '0';
                int before = ret;
                ret = ret * 10 + digit;
                if (ret % 10 != digit ||
                    ret / 10 != before) {
                    overflowed = true;
                }
                begin++;
            }

            if (overflowed) {
                if (sign > 0) {
                    ret = INT_MAX;
                } else {
                    ret = INT_MIN;
                }
            } else {
                ret *= sign;
            }
        }

        return ret;
    }
};
