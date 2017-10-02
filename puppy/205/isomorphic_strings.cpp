class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        return rebaseString(s) == rebaseString(t);
    }
    
    string rebaseString(string s) {
        map<char, char> rebases;
        int count(0);
        for (size_t i(0); i < s.size(); i++) {
            if (rebases.find(s[i]) == rebases.end()) {
                char rebaseChar = 'a' + count;
                rebases.insert(pair<char, char>(s[i], rebaseChar));
                s[i] = rebaseChar;
                count++;
            } else {
                s[i] = rebases[s[i]];
            }
        }
        return s;
    }
};
