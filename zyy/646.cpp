class Solution {
  public:
    class Pair {
      private:
        int a, b;
      public:
        int length;
        int degree;
        Pair(vector<int> &pair): a(pair[0]), b(pair[1]), length(1), degree(0) {}
        inline bool operator<(const Pair &other) const { return b < other.a; }
    };

    void topologicalSort(vector<Pair>::iterator begin, vector<Pair>::iterator end) {
        for (vector<Pair>::iterator i(begin); i != end; ++i) {
            for (vector<Pair>::iterator j(begin); j != end; ++j) {
                if (*i < *j) {
                    ++(j->degree);
                }
            }
        }

        size_t length(end - begin);
        for (size_t i(0); i < length; ++i) {
            for (vector<Pair>::iterator i(begin); i != end; ++i) {
                if (i->degree == 0) {
                    Pair tmp(*i);
                    *i = *begin;
                    *begin = tmp;
                    for (vector<Pair>::iterator j(begin); j != end; ++j) {
                        if (*begin < *j) {
                            --(j->degree);
                        }
                    }
                    begin++;
                    continue;
                }
            }
        }
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        vector<Pair> p;
        for (vector<vector<int>>::iterator i(pairs.begin()); i != pairs.end(); ++i) {
            p.push_back(Pair(*i));
        }

        topologicalSort(p.begin(), p.end());

        int ret(1);
        for (vector<Pair>::iterator i(p.begin()); i != p.end(); ++i) {
            for (vector<Pair>::iterator j(p.begin()); j != i; ++j) {
                if (*j < *i) {
                    i->length = max(j->length + 1, i->length);
                    ret = max(i->length, ret);
                }
            }
        }

        return ret;
    }
};
