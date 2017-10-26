class Solution {
  public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m((int)matrix.size()), n((int)matrix.size());
        vector<int> options;
        for (int l(0); l < k; l++) {
            for (int i(0); i <= l && i < m; i++) {
                if (l - i < n) {
                    options.push_back(matrix[i][l - i]);
                }
            }
        }

        sort(options.begin(), options.end());
        return options[k - 1];
    }
};
