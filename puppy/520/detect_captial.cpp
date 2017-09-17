class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() <= 1) {
            return true;
        }       
        string::iterator iter = word.begin();
        if (!isupper(*iter) && isupper(*(iter + 1))) {
            return false;
        }       
        
        bool is_upper = isupper(*(++iter));
        while(iter != word.end()) {
            if (is_upper && (*iter != toupper(*iter))) {
                return false;
            }
            if (!is_upper && (*iter != tolower(*iter))) {
                return false;
            }
            iter++;
        }
        return true;
    }
};
