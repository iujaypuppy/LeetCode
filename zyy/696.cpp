class Solution {
  public:
    int countBinarySubstrings(string s) {
        char leader(0);
        vector<int> counters;
        for (string::iterator i(s.begin()); i != s.end(); i++) {
            if (*i != leader) {
                leader = *i;
                counters.push_back(1);
                continue;
            }

            (*counters.rbegin())++;
        }

        int ret(0);
        for (vector<int>::iterator i(counters.begin() + 1); i != counters.end(); i++) {
            ret += min(*i, *(i - 1));
        }

        return ret;
    }
};
