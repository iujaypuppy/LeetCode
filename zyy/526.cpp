class Solution {
  public:
    /* "used" is used as bool vector */
    int countArrangement(int N, int p, unsigned int used) {
        if (N + 1 == p) {
            return 1;
        }
        int ret(0);
        for (int i(1); i <= N; i++) {
            if (((used >> i) & 1) == 1) {
                continue;
            }
            if (i % p == 0 || p % i == 0) {
                used ^= 1 << i;
                ret += countArrangement(N, p + 1, used);
                used ^= 1 << i;
            }
        }
        return ret;
    }
    int countArrangement(int N) {
        /* Why the following code is not right? */
        // vector<vector<vector<int>>> solutions;
        // solutions.push_back(vector<vector<int>>(1, vector<int>(1, 1)));
        // for (int i(2); i <= N; i++) {
        //     int p(i - 1);
        //     solutions.push_back(vector<vector<int>>());
        //     for (vector<vector<int>>::iterator j(solutions[p - 1].begin());
        //          j != solutions[p - 1].end(); j++) {
        //         vector<int> s(*j);
        //         s.push_back(i);
        //         solutions[p].push_back(s);
        //         for (int k(0); k < j->size(); k++) {
        //             if (i % (k + 1) == 0 && i % s[k] == 0) {
        //                 s[p] = s[k]; s[k] = i;
        //                 solutions[p].push_back(s);
        //                 s[k] = s[p]; s[p] = i;
        //             }
        //         }
        //     }
        // }
        // return solutions[N - 1].size();
        return countArrangement(N, 1, 0);
    }
};
