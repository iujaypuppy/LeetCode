class Solution {
  public:
    string toDecimalTime(unsigned int watch) {
        unsigned int hour(watch >> 6), minute(watch & 0x3F);
        if (hour >= 0 && hour < 12 &&
            minute >= 0 && minute < 60) {
            string h(to_string(hour));
            string mm(to_string(minute));
            if (minute < 10) {
                mm = "0" + mm;
            }
            return h + ":" + mm;
        }

        return "";
    }
    void readBinaryWatchRecursive(unsigned int watch, int level,
                                  int num, vector<string> &result) {
        if (level == 10) {
            if (num != 0) {
                return;
            }

            string time(toDecimalTime(watch));
            if (time != "") {
                result.push_back(time);
            }
            return;
        }

        if (num < 0) {
            return;
        }

        readBinaryWatchRecursive(watch | 1 << level, level + 1, num - 1, result);
        readBinaryWatchRecursive(watch, level + 1, num, result);
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        readBinaryWatchRecursive(0, 0, num, result);
        return result;
    }
};
