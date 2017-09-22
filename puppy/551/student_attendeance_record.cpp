class Solution {
public:
    bool checkRecord(string s) {
        int absents(0);
        for(string::iterator i(s.begin()); i != s.end(); i++) {
            switch (*i) {
                case 'A' :
                    absents++;
                    if (absents > 1) {
                        return false;
                    }
                    break;
                case 'L' :
                    if ((i + 1) != s.end() && *(i + 1) == 'L' &&
                        (i + 2) != s.end() && *(i + 2) == 'L') {
                        return false;
                    }
                    break;
                default :
                    continue;
            }
        }
        return true;
    }
};
