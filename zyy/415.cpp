class Solution {
  public:
    string addStrings(string num1, string num2) {
        string result;
        string::reverse_iterator i1(num1.rbegin()), i2(num2.rbegin());
        char carray(0);
        while (i1 != num1.rend() || i2 != num2.rend() || carray > 0) {
            char sum(carray);
            if (i1 != num1.rend()) {
                sum += *i1 - '0';
                i1++;
            }
            if (i2 != num2.rend()) {
                sum += *i2 - '0';
                i2++;
            }

            carray = sum / 10;
            sum %= 10;
            result = string(1, sum + '0') + result;
        }

        return result.empty() ? "0" : result;
    }
};
