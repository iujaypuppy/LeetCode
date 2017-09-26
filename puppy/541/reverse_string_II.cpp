class Solution {
public:
    string reverseStr(string s, int k) {
        int move(0), len(s.length());
        while (move < len) {
            int i = move;
            int j = (len - move >= k) ? (i + k - 1) : (len - 1);
            while (i < j) {
                s[i] = s[i] ^ s[j];
                s[j] = s[i] ^ s[j];
                s[i] = s[i] ^ s[j];
                i++;
                j--;
            }
            move += 2 * k;
        }
        return s;
    }
};
