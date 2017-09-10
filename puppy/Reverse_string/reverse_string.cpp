class Solution {
public:
    string reverseString(string s) {
        if (!s.empty()) {
            string::iterator i = s.begin();
            string::iterator j = s.end() - 1;
            while (i < j) {
                *i = *i ^ *j;
                *j = *i ^ *j;
                *i = *i ^ *j;
                i++;
                j--;
            }
        }
        return s;
    }
};
