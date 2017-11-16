class Solution {
  public:
    class DisjointSet {
      private:
        vector<int> father;
        int getFatherRecursive(int i) {
            if (father[i] != i) {
                father[i] = getFatherRecursive(father[i]);
            }
            return father[i];
        }
      public:
        DisjointSet(int n): father(n) {
            for (int i(0); i < n; i++) {
                father[i] = i;
            }
        }
        int getFather(int n) {
            return getFatherRecursive(n - 1);
        }
        bool merge(int a, int b) {
            if (getFather(a) == getFather(b)) {
                return false;
            }
            father[getFather(a)] = father[getFather(b)];
            return true;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet set(edges.size());
        for (vector<vector<int>>::iterator i(edges.begin());
             i != edges.end(); i++) {
            vector<int> &edge(*i);
            if (!set.merge(edge[0], edge[1])) {
                return edge;
            }
        }

        return vector<int>();
    }
};
