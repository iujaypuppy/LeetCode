class Solution {
  public:
    int countBattleships(vector<vector<char>>& board) {
        size_t n(board.size()), m(board[0].size());
        int count(0);
        for (size_t i(0); i < n; i++) {
            for (size_t j(0); j < m; j++) {
                if (board[i][j] == 'X' &&
                    (i == 0 || board[i - 1][j] != 'X') &&
                    (j == 0 || board[i][j - 1] != 'X')) {
                    count++;
                }
            }
        }
        return count;
    }
};
