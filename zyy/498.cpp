class Solution {
  public:
    class Coordinate {
      private:
        int x, y, m, n;
      public:
        Coordinate(int mm, int nn, int xx = 0, int yy = 0): m(mm), n(nn), x(xx), y(yy) {}
        bool go(bool &goUp) {
            if (goUp) {
                if (x > 0 && y < n - 1) {
                    x--;
                    y++;
                    return true;
                }
                goUp = !goUp;
                if (y < n - 1) {
                    y++;
                    return true;
                }

                if (x < m - 1) {
                    x++;
                    return true;
                }
                return false;
            }

            if (x < m - 1 && y > 0) {
                x++;
                y--;
                return true;
            }
            goUp = !goUp;
            if (x < m - 1) {
                x++;
                return true;
            }
            if (y < n - 1) {
                y++;
                return true;
            }
            return false;
        }
        int get(vector<vector<int>> &matrix) {
            return matrix[x][y];
        }
    };
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return vector<int>();
        }
        bool goUp(true);
        Coordinate c(matrix.size(), matrix[0].size());
        vector<int> ret;
        do {
            ret.push_back(c.get(matrix));
        } while (c.go(goUp));
        return ret;
    }
};
