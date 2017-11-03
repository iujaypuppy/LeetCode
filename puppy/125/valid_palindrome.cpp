class Solution {
public:
    bool isPalindrome(string s) {
        s = removeIgnoreChars(s);
        
        if (s.empty()) {
            return true;
        }
        
        string::iterator i(s.begin());
        string::iterator j(s.end() - 1);
        while (i < j) {
            if (*i != *j) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    string removeIgnoreChars(string s) {
        string res("");
        for (string::iterator i(s.begin()); i != s.end(); i++) {
            if (isAlphaNumeric(*i)) {
                res += tolower(*i);
            }
        }
        return res;
    }
    
    bool isAlphaNumeric(char c) {
        return isalpha(c) || isdigit(c);
    }
};
