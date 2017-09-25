class Solution {
  public:
    int lengthOfLastWord(string s) {
        string::reverse_iterator i(s.rbegin());
        while (i != s.rend() && isspace(*i)) {
            i++;
        }

        string::reverse_iterator j(i);
        while (j != s.rend() && !isspace(*j)) {
            j++;
        }

        return j - i;
    }
};
