class RebaseString {
private:
    string str;
    string rebaseStr;
    
    string pattern;
    string rebasePattern;
    
    void doRebaseStrByChar(char split) {
        map<string, char> rebases;
        int count(0);
        string tmp(""), tmpStr(str + split);
        for (size_t i(0); i < tmpStr.size(); i++) {
            if (tmpStr[i] == split) {
                if (rebases.find(tmp) != rebases.end()) {
                    rebaseStr += rebases[tmp];
                } else {
                    char rebaseChar = 'a' + count;
                    rebaseStr += rebaseChar;
                    rebases.insert(pair<string, char>(tmp, rebaseChar));
                    count++;
                }
                tmp = "";
            } else {
                tmp += tmpStr[i];
            }
        }
    }
    
    void doRebasePattern() {
        map<char, char> rebases;
        int count(0);
        for (size_t i(0); i < pattern.size(); i++) {
            if (rebases.find(pattern[i]) != rebases.end()) {
                rebasePattern += rebases[pattern[i]];
            } else {
                char rebaseChar = 'a' + count;
                rebasePattern += rebaseChar;
                rebases.insert(pair<char, char>(pattern[i], rebaseChar));
                count++;
            }
        }
    }
    
public:
    RebaseString(string s, string p) : str(s), pattern(p) {
        rebaseStr = "";
        rebasePattern = "";
    }
    
    bool isWordPattern() {
        return rebaseStr == rebasePattern;
    }
   
    void doRebase() {
        doRebaseStrByChar(' ');
        doRebasePattern();
    }
};

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        RebaseString rebaseStr(str, pattern);
        rebaseStr.doRebase();
        return rebaseStr.isWordPattern();
    }
};
