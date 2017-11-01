class Solution {
  public:
    class LogEntry {
      private:
        int fid, ts, callerTime;
        bool start;
      public:
        LogEntry(string s): callerTime(0) {
            start = (s.find(":start:") != string::npos);
            string mid(start ? ":start:" : ":end:");
            size_t fidEnd(s.find(mid));
            fid = atoi(s.substr(0, fidEnd).c_str());
            ts = atoi(s.substr(fidEnd + mid.length()).c_str());
        }
        bool call(void) const { return start; }
        void call(int time) {
            callerTime += time;
        }
        int time(int end) const { return end - ts + 1; }
        int exclusiveTime(int end) const { return time(end) - callerTime; }
        int timestamp(void) const { return ts; }
        int id(void) const { return fid; }
    };
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> stat(n, 0);
        stack<LogEntry> s;
        for (vector<string>::iterator i(logs.begin()); i != logs.end(); i++) {
            LogEntry log(*i);
            if (log.call()) {
                s.push(log);
                continue;
            }

            stat[log.id()] += s.top().exclusiveTime(log.timestamp());
            int time(s.top().time(log.timestamp()));
            s.pop();
            if (!s.empty()) {
                s.top().call(time);
            }
        }

        return stat;
    }
};
