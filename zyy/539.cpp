class Solution {
  public:
    class Time {
      private:
        int hour, minute;
      public:
        Time(const string &time) {
            const char *str(time.c_str());
            hour = atoi(str);
            minute = atoi(str + 3);
        }
        bool operator<(const Time &other) const {
            return hour < other.hour || (hour == other.hour && minute < other.minute);
        }
        int operator-(const Time &other) const {
            int h(hour - other.hour), m(minute - other.minute);
            int ret(abs(h * 60 + m));
            return min(ret, 24 * 60 - ret);
        }
    };
    int findMinDifference(vector<string>& timePoints) {
        vector<Time> times;
        for (vector<string>::iterator i(timePoints.begin()); i != timePoints.end(); i++) {
            times.push_back(Time(*i));
        }
        sort(times.begin(), times.end());
        int ret(24 * 60);
        for (vector<Time>::iterator i(times.begin() + 1); i != times.end(); i++) {
            ret = min(*i - *(i - 1), ret);
        }

        return min(ret, *times.begin() - *times.rbegin());
    }
};
