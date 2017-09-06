class Solution {
  public:
    void trim(const string &str, const string::iterator &start,
              /* the following are return values */
              string::iterator &left, string::iterator &right) {
        for (left = start;
             left != str.end() && isspace(*left);
             left++) {}

        right = left;

        while (right != str.end() && !isspace(*right)) {
            right++;
        }
    }

    void reverse(string::iterator left, string::iterator right) {
        while (left < right) {
            char tmp = *left;
            *left = *right;
            *right = tmp;
            
            left++;
            right--;
        }
    }

    string reverseWords(string s) {
        string::iterator left, right, start(s.begin());
        do {
            trim(s, start, left, right);
            reverse(left, right - 1);
            start = right;
        } while(left < right);

        return s;
    }
};
