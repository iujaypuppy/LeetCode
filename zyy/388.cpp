class Solution {
  public:
    bool getSubstring(string::iterator begin, string::iterator end,
                      string::iterator &retBegin, string::iterator &retEnd) {
        if (begin == end) {
            return false;
        }
        retBegin = begin;
        while (begin != end && (*begin == '\n' || *begin == '\t')) {
            begin++;
        }
        while (begin != end && !(*begin == '\n' || *begin == '\t')){
            begin++;
        }
        retEnd = begin;
        return true;
    }

    class Path {
      private:
        vector<string> dirs;
      public:
        Path(void) {}
        void cd(string::iterator begin, string::iterator end) {
            while (begin != end && *begin == '\n') {
                begin++;
            }
            int level(0);
            while (begin != end && *begin == '\t') {
                level++;
                begin++;
            }
            if (begin == end) {
                return;
            }

            dirs.resize(level);
            dirs.push_back(string(begin, end));
        }
        int length(void) {
            int ret(0);
            for (vector<string>::iterator i(dirs.begin()); i != dirs.end(); i++) {
                ret += i->length();
            }
            return ret + (dirs.empty() ? 0 : dirs.size() - 1);
        }
    };

    bool isFile(string::iterator begin, string::iterator end) {
        for (string::iterator i(begin); i != end; i++) {
            if (*i == '.') {
                return true;
            }
        }
        return false;
    }

    int lengthLongestPath(string input) {
        string::iterator begin(input.begin()), end(input.end()), subBegin, subEnd;
        Path path;
        int ret(0);
        while (getSubstring(begin, end, subBegin, subEnd)) {
            begin = subEnd;
            path.cd(subBegin, subEnd);
            if (isFile(subBegin, subEnd)) {
                int length(path.length());
                ret = max(length, ret);
            }
        }
        return ret;
    }
};
