class Solution {
  public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) {
            return vector<int>();
        }

        static const int BASE = 10;
        (*digits.rbegin())++;
        int carry(*digits.rbegin() / BASE);
        *digits.rbegin() %= BASE;
        for (vector<int>::reverse_iterator i(digits.rbegin() + 1);
             i != digits.rend() && carry != 0; i++) {
            (*i) += carry;
            carry = *i / BASE;
            *i %= BASE;
        }

        if (carry != 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
