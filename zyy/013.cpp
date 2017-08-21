class Solution {
  public:
    class RomanDigit {
      private:
        vector< pair<int, char> > table;
      public:
        RomanDigit(void) {
            table.push_back(make_pair(1000, 'M'));
            table.push_back(make_pair(500, 'D'));
            table.push_back(make_pair(100, 'C'));
            table.push_back(make_pair(50, 'L'));
            table.push_back(make_pair(10, 'X'));
            table.push_back(make_pair(5, 'V'));
            table.push_back(make_pair(1, 'I'));
        }

        int romanToIntDigit(char digit) {
            for (vector< pair<int, char> >::iterator i = table.begin();
                 i != table.end(); i++) {
                if (i->second == digit) {
                    return i->first;
                }
            }
            return 0;
        }
    };

    int romanToInt(string s) {
        int sum(0);
        RomanDigit table;

        for (string::iterator i = s.begin(); i != s.end(); i++) {
            int digit = table.romanToIntDigit(*i);
            int next(0);
            if (i + 1 != s.end()) {
                next = table.romanToIntDigit(*(i + 1));
            }

            if (next > digit) {
                digit *= -1;
            }

            sum += digit;
        }

        return sum;
    }
};
