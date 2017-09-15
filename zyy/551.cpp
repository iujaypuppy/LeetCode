class Solution {
  public:
    bool checkRecord(string s) {
        char last('P');
        size_t count(0), absent(0);
        for (string::iterator i(s.begin()); i != s.end(); i++) {
            if (last == *i) {
                count++;
            } else {
                count = 1;
                last = *i;
            }

            if (*i == 'A') {
                absent++;
            }

            if (last == 'L' && count > 2) {
                return false;
            }
        }

        return !(absent > 1);
    }
};
