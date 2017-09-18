class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        vector<int>::iterator i(g.begin());
        vector<int>::iterator j(s.begin());
        int sum = 0;
        for (i; i != g.end(); i++) {
            while (j != s.end()) {
                if (*j >= *i) {
                    sum++;
                    j++;
                    break;
                }
                j++;
            }
        }
        return sum;
    }
};
