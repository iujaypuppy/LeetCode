class Solution {
  public:
    int leastBricks(vector<vector<int>>& wall) {
        /* calculate all end point of bricks */
        for (vector<vector<int>>::iterator i(wall.begin()); i != wall.end(); i++) {
            int sum(0);
            for (vector<int>::iterator j(i->begin()); j != i->end(); j++) {
                sum += *j;
                *j = sum;
            }
            i->erase(i->end() - 1);
        }

        vector<size_t> p(wall.size(), 0);
        int last(0), ret(wall.size());
        while (true) {
            int cut(-1);
            for (size_t i(0); i < wall.size(); i++) {
                for (size_t j(p[i]); j < wall[i].size(); j++) {
                    if (cut == -1 || wall[i][j] < cut) {
                        cut = wall[i][j];
                    }
                }
            }

            if (cut == -1) {
                break;
            }

            int breaks(0);
            for (size_t i(0); i < wall.size(); i++) {
                while (p[i] < wall[i].size() && wall[i][p[i]] < cut) {
                    p[i]++;
                }
                if (p[i] < wall[i].size() && wall[i][p[i]] == cut) {
                    while (p[i] < wall[i].size() && wall[i][p[i]] == cut) {
                        p[i]++;
                    }
                    continue;
                }
                breaks++;
            }
            ret = min(ret, breaks);
        }

        return ret;
    }
};
