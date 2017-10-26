class Solution {
  public:
    int minSteps(int n) {
#if 0
        /* Memory Limit Exceeded */
        /*
          t[i][j] means it takes t[i][j] steps to reach the following state:
            1. count of 'A' is i;
            2. the clipboard contains j 'A's.
        */
        vector<vector<int>> t(n + 1, vector<int>(n + 1, n));
        t[1][0] = 0;
        for (int i(1); i <= n; i++) {
            int minimum(n);
            for (int j(0); j <= n; j++) {
                minimum = min(minimum, t[i][j]);
            }
            t[i][i] = minimum + 1;

            for (int j(0); j <= n && i + j <= n; j++) {
                t[i + j][j] = min(t[i][j] + 1, t[i + j][j]);
            }
        }

        int ret(n);
        for (int i(0); i <= n; i++) {
            ret = min(ret, t[n][i]);
        }

        return ret;
#endif
        vector<int> t(n + 1, n);
        t[1] = 0;
        for (int i(2); i <= n; i++) {
            for (int j(1); j < i; j++) {
                if (i % j == 0) {
                    t[i] = min(t[i], t[j] + i / j);
                }
            }
        }

        return t[n];
    }
};
