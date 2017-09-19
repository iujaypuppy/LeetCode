class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> counts(52, 0);
        for (string::iterator i(s.begin()); i != s.end(); i++) {
            if (isupper(*i)) {
                counts[*i - 'A' + 26]++;
            } else {
                counts[*i - 'a']++;
            }
        }
        int res(0);
        bool exist_single(false);
        for (vector<int>::iterator i(counts.begin()); i != counts.end(); i++) {
            res += (*i & 0x01) ? (*i - 1) : *i;
            exist_single = exist_single || (*i & 0x01);
        }
        res += (exist_single) ? 1 : 0;
        return res;
    }
};
