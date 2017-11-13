class Solution {
  public:
    int sqr(int n) { return n * n; }
    int distance(vector<int> &a, vector<int> &b) {
        return sqr(a[0] - b[0]) + sqr(a[1] - b[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> dist;
        dist.push_back(distance(p1, p2));
        dist.push_back(distance(p1, p3));
        dist.push_back(distance(p1, p4));
        dist.push_back(distance(p2, p3));
        dist.push_back(distance(p2, p4));
        dist.push_back(distance(p3, p4));
        sort(dist.begin(), dist.end());
        return dist[0] == dist[1] && dist[1] == dist[2] &&
                dist[2] == dist[3] && dist[0] != 0;
    }
};
