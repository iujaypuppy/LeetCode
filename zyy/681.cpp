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
            int ret(h * 60 + m);
            return ret <= 0 ? ret + 24 * 60 : ret;
        }
        bool valid(void) const { return hour >= 0 && hour < 24 && minute >= 0 && minute < 60; }
    };

    string nextClosestTime(string time) {
        Time t(time);
        string ret(time), old(time);
        int min(24 * 60);
        time.erase(time.begin() + 2);
        for (size_t i(0); i < time.length(); i++) {
            for (size_t j(0); j < time.length(); j++) {
                for (size_t k(0); k < time.length(); k++) {
                    for (size_t l(0); l < time.length(); l++) {
                        string tmp(string(1, time[i]) + time[j] + ":" + time[k] + time[l]);
                        if (tmp == old) {
                            continue;
                        }
                        Time tmpTime(tmp);
                        if (!tmpTime.valid()) {
                            continue;
                        }
                        if (tmpTime - t < min) {
                            ret = tmp;
                            min = tmpTime - t;
                        }
                    }
                }
            }
        }

        return ret;
    }
};
