class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> smooth_m;
        for (size_t i(0); i < M.size(); i++) {
            vector<int> row;
            for (size_t j(0); j < M[i].size(); j++) {
                int val = smooth_cell_val(M, i, j);
                row.push_back(val);
            }
            smooth_m.push_back(row);
        }
        return smooth_m;
    }
    
    int smooth_cell_val(vector<vector<int>>& M, int i, int j) {
        int count(1), sum(M[i][j]);
        int row(M.size()), col(M[0].size());
        if ((i - 1 >= 0) && (j - 1 >= 0)) {
            count++;
            sum += M[i - 1][j - 1];
        }
        if ((i - 1 >= 0) && (j >= 0)) {
            count++;
            sum += M[i - 1][j];
        }
        if ((i - 1 >= 0) && (j + 1 < col)) {
            count++;
            sum += M[i - 1][j + 1];
        }
        if ((i >= 0) && (j - 1 >= 0)) {
            count++;
            sum += M[i][j - 1];
        }
        if ((i >= 0) && (j + 1 < col)) {
            count++;
            sum += M[i][j + 1];
        }
        if ((i + 1 < row) && (j - 1 >= 0)) {
            count++;
            sum += M[i + 1][j - 1];
        }
        if ((i + 1 < row) && (j >= 0)) {
            count++;
            sum += M[i + 1][j];
        }
        if ((i + 1 < row) && (j + 1 < col)) {
            count++;
            sum += M[i + 1][j + 1];
        }
        return sum / count;
    }
};
