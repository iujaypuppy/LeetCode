class Solution {
  public:
    int isMine(vector<vector<char>> &board, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
            return 0;
        }
        if (board[x][y] == 'M' || board[x][y] == 'X') {
            return 1;
        }
        return 0;
    }
    int countMines(vector<vector<char>> &board, int x, int y) {
        return isMine(board, x + 1, y) +
                isMine(board, x - 1, y) +
                isMine(board, x, y + 1) +
                isMine(board, x, y - 1) +
                isMine(board, x - 1, y - 1) +
                isMine(board, x - 1, y + 1) +
                isMine(board, x + 1, y - 1) +
                isMine(board, x + 1, y + 1);
    }
    void revealEmpty(vector<vector<char>> &board, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
            return;
        }

        if (board[x][y] != 'E') {
            return;
        }

        int mines(countMines(board, x, y));
        if (mines == 0) {
            board[x][y] = 'B';
            revealEmpty(board, x + 1, y);
            revealEmpty(board, x - 1, y);
            revealEmpty(board, x, y + 1);
            revealEmpty(board, x, y - 1);
            revealEmpty(board, x - 1, y - 1);
            revealEmpty(board, x - 1, y + 1);
            revealEmpty(board, x + 1, y - 1);
            revealEmpty(board, x + 1, y + 1);
            return;
        }
        board[x][y] = '0' + mines;
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        switch (board[click[0]][click[1]]) {
            case 'M':
                board[click[0]][click[1]] = 'X';
                break;
            case 'E':
                revealEmpty(board, click[0], click[1]);
                break;
            default:
                break;
        }

        return board;
    }
};
