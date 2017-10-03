class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string res;
        size_t i(0);
        int carry(0);
        while (i < a.size() || i < b.size()) {
            int m = (i < a.size()) ? (a[i] - '0') : 0;
            int n = (i < b.size()) ? (b[i] - '0') : 0;
            int sum = m + n + carry;
            res += (sum & 0x01) ? '1' : '0';
            carry = (sum >= 2) ? 1 : 0;
            i++;
        }
        res += (carry) ? "1" : "";
        
        reverse(res.begin(), res.end());
        return res;
    }
};
