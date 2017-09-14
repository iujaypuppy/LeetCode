class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_m(m), min_n(n);
        for (vector<vector<int>>::iterator iter(ops.begin()); iter != ops.end(); iter++) {
            min_m = min(min_m, (*iter)[0]);
            min_n = min(min_n, (*iter)[1]);
        }
        return min_m * min_n;
    }
};
