class Solution {
  public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<int> AB, CD;
        for (vector<int>::iterator a(A.begin()); a != A.end(); a++) {
            for (vector<int>::iterator b(B.begin()); b != B.end(); b++) {
                AB.push_back(*a + *b);
            }
        }

        for (vector<int>::iterator c(C.begin()); c != C.end(); c++) {
            for (vector<int>::iterator d(D.begin()); d != D.end(); d++) {
                CD.push_back(*c + *d);
            }
        }


        sort(AB.begin(), AB.end());
        sort(CD.begin(), CD.end());
        int ret(0);
        int lastSum, lastCount(-1);
        vector<int>::reverse_iterator cd(CD.rbegin());
        for (vector<int>::iterator ab(AB.begin()); ab != AB.end(); ab++) {
            if (lastCount != -1 && *ab == lastSum) {
                ret += lastCount;
                continue;
            }
            int prevRet(ret);

            while (cd != CD.rend() && *cd + *ab > 0) {
                cd++;
            }

            for (vector<int>::reverse_iterator i(cd); i != CD.rend() && *i + *ab == 0; i++) {
                ret++;
            }

            lastSum = *ab;
            lastCount = ret - prevRet;
        }

        return ret;
    }
};
