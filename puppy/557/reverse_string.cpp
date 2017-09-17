class Solution {
public:
    string reverseWords(string s) {
        int i=0, j=0;
        while(j != s.size()) {
            if ((j == s.size()-1) || (s[j+1] == ' ') {
                int start = i, end = j;
                while (start < end) {
                    char tmp = s[start];
                    s[start] = s[end];
                    s[end] = tmp;
                    start++;
                    end--;
                }
            }
            j++
        }
        return s;
    }
};
