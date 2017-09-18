class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> chars(26, 0);
        for (string::iterator i(s.begin()); i != s.end(); i++) {
            chars[*i - 'a']++;
        }
        for (string::iterator i(s.begin()); i != s.end(); i++) {
            if (chars[*i - 'a'] == 1) {
                return (i - s.begin());
            }
        }
        return -1;
    }
};
