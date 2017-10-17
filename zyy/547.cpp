class Solution {
  public:
    class DisjointSet {
      private:
        vector<int> circles;
      public:
        DisjointSet(int n): circles(n) {
            for (size_t i(0); i < circles.size(); ++i) {
                circles[i] = (int)i;
            }
        }
        int getCircle(int k) {
            if (circles[k] != k) {
                circles[k] = getCircle(circles[k]);
            }
            return circles[k];
        }
        void mergeCircle(int a, int b) {
            circles[getCircle(a)] = circles[getCircle(b)];
        }
        int countCircles(void) {
            /* Compress all fathers of this disjoint set */
            for (size_t i(0); i < circles.size(); i++) {
                getCircle((int)i);
            }
            vector<bool> circleIdUsed(circles.size(), false);
            for (vector<int>::iterator i(circles.begin()); i != circles.end(); ++i) {
                circleIdUsed[*i] = true;
            }
            int count(0);
            for (vector<bool>::iterator i(circleIdUsed.begin()); i != circleIdUsed.end(); ++i) {
                if (*i) {
                    ++count;
                }
            }
            return count;
        }
    };
    int findCircleNum(vector<vector<int>>& M) {
        DisjointSet circles(M.size());
        for (size_t i(0); i < M.size(); ++i) {
            for (size_t j(0); j < M.size(); ++j) {
                if (M[i][j] == 1) {
                    circles.mergeCircle(i, j);
                }
            }
        }

        return circles.countCircles();
    }
};
