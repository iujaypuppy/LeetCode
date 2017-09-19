class Solution {
  public:
    string addBinary(string a, string b) {
        string ret;
        string::reverse_iterator i(a.rbegin()), j(b.rbegin());
        int carry(0);
        while (i != a.rend() || j != b.rend() || carry != 0) {
            int sum(carry);
            if (i != a.rend()) {
                sum += *i - '0';
                i++;
            }
            if (j != b.rend()) {
                sum += *j - '0';
                j++;
            }
            carry = sum / 2;
            sum %= 2;
            ret = string(1, '0' + sum) + ret;
        }

        return ret.empty() ? "0" : ret;
    }
};
