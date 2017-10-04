class Solution {
public:
    int lengthOfLastWord(string s) {
        int count(0);
        for (size_t i(s.size()); i > 0; i--) {
            if (s[i - 1] == ' ') {
                if (count) {
                    break;
                }             
            } else {
                count++;
            }
        }
        return count;
    }
};
