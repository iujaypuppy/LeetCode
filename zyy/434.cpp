class Solution {
  public:
    int countSegments(string s) {
        int result(0);

        string::iterator i(s.begin());
        while (i != s.end()) {
            while (i != s.end() && isspace(*i)) {
                i++;
            }
            if (i == s.end()) {
                break;
            }

            while (i != s.end() && !isspace(*i)) {
                i++;
            }
            result++;
        }

        return result;
    }
};
