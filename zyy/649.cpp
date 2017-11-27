class Solution {
  public:
    string::iterator cyclicNext(string &senate, string::iterator p) {
        p = p + 1;
        return p == senate.end() ? senate.begin() : p;
    }
    string::iterator next(string &senate, string::iterator p) {
        do {
            p = cyclicNext(senate, p);
        } while (*p != 'D' && *p != 'R');
        return p;
    }
    string predictPartyVictory(string senate) {
        int r(0), d(0);
        for (string::iterator i(senate.begin()); i != senate.end(); i++) {
            if (*i == 'D') {
                d++;
                continue;
            }
            if (*i == 'R') {
                r++;
                continue;
            }
        }

        string::iterator i(senate.begin());
        while (r > 0 && d > 0) {
            string::iterator j(next(senate, i));
            while (*j == *i) {
                j = next(senate, j);
            }
            if (*j == 'D') {
                d--;
            } else if (*j == 'R') {
                r--;
            }
            *j = 'B';
            i = next(senate, i);
        }
        return r > 0 ? "Radiant" : "Dire";
    }
};
