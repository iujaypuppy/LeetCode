class Solution {
  public:
    void reverse(string::iterator left, string::iterator right) {
        while (left < right) {
            char tmp = *left;
            *left = *right;
            *right = tmp;

            left++;
            right--;
        }
    }

    string reverseStr(string s, int k) {
        for (size_t i(0); i < s.length(); i += 2 * k) {
            reverse(s.begin() + i, s.begin() + min(i + k, s.length()) - 1);
        }

        return s;
    }
};
