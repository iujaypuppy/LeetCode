class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.empty()) {
            return num2;
        }
        if(num2.empty()) {
            return num1;
        }
        
        string add_str("");
        int i(0), carry(0);
        int num1_size(num1.size()), num2_size(num2.size());
        while(i < num1_size || i < num2_size || carry) {
            int sum = carry;
            if (i < num1_size) {
                sum += (num1[num1_size - i - 1] - '0');
            }
            if (i < num2_size) {
                sum += (num2[num2_size - i - 1] - '0');
            }
            add_str += (char)('0' + sum % 10);
            carry = sum / 10;
            i++;
        }
        
        reverse(add_str.begin(), add_str.end());
        return add_str;
    }
};
