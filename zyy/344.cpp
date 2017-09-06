class Solution {
  public:
    string reverseString(string s) {
        string::iterator left(s.begin()), right(s.end() - 1);

        while (left < right) {
            char tmp = *left;
            *left = *right;
            *right = tmp;
            left++;
            right--;
        }

        return s;
    }
};
