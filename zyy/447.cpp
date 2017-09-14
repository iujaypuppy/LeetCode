class Solution {
  public:
    static inline int sqr(int n) { return n * n; }
    static inline int sqrDistance(const pair<int, int>& a, const pair<int, int>& b) {
        return sqr(a.first - b.first) + sqr(a.second - b.second);
    }

    class DistanceMap {
      private:
        static const size_t MAX = 500;
        int distances[MAX][MAX];
      public:
        DistanceMap(const vector<pair<int, int>> &p) {
            for (size_t i(0); i < p.size(); i++) {
                distances[i][i] = 0;
                for (size_t j(i + 1); j < p.size(); j++) {
                    distances[i][j] = distances[j][i] = sqrDistance(p[i], p[j]);
                }
            }
        }

        int distance(size_t i, size_t j) const { return distances[i][j]; }
    };

    int numberOfBoomerangs(vector<pair<int, int>> &points) {
        int result(0);
        DistanceMap map(points);

        for (size_t i(0); i < points.size(); i++) {
            for (size_t j(0); j < points.size(); j++) {
                if (i == j) {
                    continue;
                }
                for (size_t k(j + 1); k < points.size(); k++) {
                    if (i == k) {
                        continue;
                    }
                    if (map.distance(i, j) == map.distance(i, k)) {
                        result++;
                    }
                }
            }
        }

        return result * 2;
    }
};
