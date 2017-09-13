class Solution {
  public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        vector<int>::iterator j(s.begin());
        int total(0);
        for (vector<int>::iterator i(g.begin()); i != g.end(); i++) {
            while (j != s.end() && *i > *j) {
                j++;
            }

            if (j == s.end()) {
                break;
            }

            j++;
            total++;
        }

        return total;
    }
};
