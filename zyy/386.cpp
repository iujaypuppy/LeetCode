class Solution {
  public:
    void lexicalOrder(int n, int cur, vector<int> &ret) {
        for (int i(0); i <= 9; i++) {
            if (cur == 0 && i == 0) {
                continue;
            }
            int k(cur * 10 + i);
            if (k > n) {
                break;
            }
            ret.push_back(k);
            lexicalOrder(n, k, ret);
        }
    }
    vector<int> lexicalOrder(int n) {
        if (n < 1) {
            return vector<int>();
        }
        vector<int> ret;
        lexicalOrder(n, 0, ret);
        return ret;
    }
};
