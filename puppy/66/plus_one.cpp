class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry(0), len(digits.size());
        digits[len - 1]++;
        for (int i(len - 1); i >=0; i--) {
            if (digits[i] + carry <= 9) {
                digits[i] += carry;
                return digits;
            }
            digits[i] = 0;
            carry = 1;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
