class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alphts(26, 0);
        for (string::iterator i(s.begin()); i != s.end(); i++) {
            alphts[*i - 'a']++;
        }
        for (string::iterator i(t.begin()); i != t.end(); i++) {
            alphts[*i - 'a']--;
        }
        for (vector<int>::iterator i(alphts.begin()); i != alphts.end(); i++) {
            if (*i != 0) {
                return false;
            }
        }
        return true;
    }
};
