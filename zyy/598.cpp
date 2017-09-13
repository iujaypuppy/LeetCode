class Solution {
  public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (vector<vector<int>>::iterator op(ops.begin());
             op != ops.end(); op++) {
            int a((*op)[0]), b((*op)[1]);
            if (a < m) {
                m = a;
            }

            if (b < n) {
                n = b;
            }
        }

        return m * n;
    }
};
