class Solution {
  public:
    int countSubstrings(string s) {
        size_t length(s.length());
        int count(0);
        for (string::iterator axis(s.begin()); axis != s.end(); axis++) {
            for (size_t i(0); i < min(axis - s.begin() + 1, s.end() - axis); i++) {
                string::iterator begin(axis - i), end(axis + i);
                if (*begin != *end) {
                    break;
                }
                count++;
            }
            for (size_t i(0); i < min(axis - s.begin() + 1, s.end() - axis - 1); i++) {
                string::iterator begin(axis - i), end(axis + i + 1);
                if (*begin != *end) {
                    break;
                }
                count++;
            }
        }

        return count;
    }
};
