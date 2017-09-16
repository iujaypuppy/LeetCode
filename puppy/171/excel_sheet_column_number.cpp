class Solution {
public:
    int titleToNumber(string s) {
        unsigned int res = 0;
        unsigned int carry = 1;
        for(string::iterator iter(s.end()-1); iter >= s.begin(); iter--) {
            res += (*iter - 'A' + 1) * carry;
            carry *= 26;
        }
        return res;
    }
};
