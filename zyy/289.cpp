class Solution {
  public:
    int checkLiveness(vector<vector<int>>& board, int x, int y) {
        int n(0);
        for (int i(x - 1); i <= (x + 1); i++) {
            if (i < 0 || i >= board.size()) {
                continue;
            }
            for (int j(y - 1); j <= (y + 1); j++) {
                if (j < 0 || j >= board[0].size()) {
                    continue;
                }
                if (i == x && j == y) {
                    continue;
                }
                if (board[i][j] == 1) {
                    n++;
                }
            }
        }
        if (n < 2) {
            return 0;
        }
        if (n == 3) {
            return 1;
        }
        if (n > 3) {
            return 0;
        }
        if (n >= 2 && n <= 3) {
            return board[x][y];
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ret(board.size(), vector<int>(board[0].size()));
        for (int i(0); i < (int)board.size(); i++) {
            for (int j(0); j < (int)board[0].size(); j++) {
                ret[i][j] = checkLiveness(board, i, j);
            }
        }
        board = ret;
    }
};
