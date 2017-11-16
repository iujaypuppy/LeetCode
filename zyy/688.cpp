class Solution {
  public:
    double getOutProbability(vector<vector<double>> &p, int x, int y) {
        if (x < 0 || x >= (int)p.size() || y < 0 || y >= (int)p[0].size()) {
            return 1.0;
        }

        return p[x][y];
    }

    double knightProbability(int N, int K, int r, int c) {
        /* p[k][i][j] means, for k step, (i, j) has probability of p[k][i][j] to move off */
        vector<vector<vector<double>>> p(K + 1, vector<vector<double>>(N,
                                                                       vector<double>(N, 0.0)));
        for (int k(1); k <= K; k++) {
            for (int i(0); i < N; i++) {
                for (int j(0); j < N; j++) {
                    int x, y;

                    x = i + 2;
                    y = j + 1;
                    p[k][i][j] += 1.0 / 8 * getOutProbability(p[k - 1], x, y);
                    y = j - 1;
                    p[k][i][j] += 1.0 / 8 * getOutProbability(p[k - 1], x, y);

                    x = i - 2;
                    y = j + 1;
                    p[k][i][j] += 1.0 / 8 * getOutProbability(p[k - 1], x, y);
                    y = j - 1;
                    p[k][i][j] += 1.0 / 8 * getOutProbability(p[k - 1], x, y);

                    x = i + 1;
                    y = j + 2;
                    p[k][i][j] += 1.0 / 8 * getOutProbability(p[k - 1], x, y);
                    y = j - 2;
                    p[k][i][j] += 1.0 / 8 * getOutProbability(p[k - 1], x, y);

                    x = i - 1;
                    y = j + 2;
                    p[k][i][j] += 1.0 / 8 * getOutProbability(p[k - 1], x, y);
                    y = j - 2;
                    p[k][i][j] += 1.0 / 8 * getOutProbability(p[k - 1], x, y);
                }
            }
        }
        return 1 - p[K][r][c];
    }
};
