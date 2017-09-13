class Solution {
  public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> result(M.size(), vector<int>(M[0].size(), 0));

        for (size_t i(0); i < M.size(); i++) {
            for (size_t j(0); j < M[0].size(); j++) {
                int count(0);
                for (int ii((int)i - 1); ii <= (int)i + 1; ii++) {
                    if (ii < 0 || ii >= (int)M.size()) {
                        continue;
                    }
                    for (int jj((int)j - 1); jj <= (int)j + 1; jj++) {
                        if (jj < 0 || jj >= (int)M[0].size()) {
                            continue;
                        }
                        result[i][j] += M[ii][jj];
                        count++;
                    }
                }

                result[i][j] /= count;
            }
        }
        return result;
    }
};
