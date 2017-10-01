class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        if (len <= 1) {
            return false;
        }
        
        string::iterator repeated(s.begin());
        for (string::iterator i(s.begin() + 1); i != s.end(); i++) {
            if (*i != *repeated) {
                continue;
            }
            
            int step = i - repeated;
            if (len % step != 0 || len / step == 1) {
                continue;
            }
            
            if (is_repeated_by_step(s, step)) {
                return true;
            }
        }
        return false;
    }
    
    bool is_repeated_by_step(string s, int step) {
        for (size_t i(step); i < s.size(); i += step) {
            for (size_t j(i); j < step + i; j++) {
                if (s[j] != s[j - step]) {
                    return false;
                }
            }
        }
        return true;
    }
};
