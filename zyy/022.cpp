class Solution {
  public:
    void generateParenthesisRecursive(string intermediate,
                                      int rest,
                                      int stack,
                                      int n,
                                      vector<string> &results) {
        if (rest == 0) {
            results.push_back(intermediate);
            return;
        }
        if (n > 0) {
            generateParenthesisRecursive(intermediate + '(', rest - 1, stack + 1, n - 1, results);
        }
        if (stack > 0) {
            generateParenthesisRecursive(intermediate + ')', rest - 1, stack - 1, n, results);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generateParenthesisRecursive("", n * 2, 0, n, ret);
        return ret;
    }
};
