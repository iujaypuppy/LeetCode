class Solution {
  public:
    const char *KEYBOARD[10] = {
        " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
    };
    void letterCombinationsRecursive(const string &digits, string current,
                                     vector<string> &results) {
        if (digits.length() == 0) {
            if (current.length() > 0) {
                results.push_back(current);
            }
            return;
        }

        int digit = digits[0] - '0';
        size_t buttonLength = strlen(KEYBOARD[digit]);
        string next = digits.substr(1);
        for (size_t i = 0; i < buttonLength; i++) {
            current += KEYBOARD[digit][i];
            letterCombinationsRecursive(next, current, results);
            current.erase(current.end() - 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        letterCombinationsRecursive(digits, "", ret);
        return ret;
    }
};
