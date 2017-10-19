class Solution {
  public:
    class State {
      private:
      public:
        vector<bool> bulbs;
        int steps;
        State(int size, int s = 0): bulbs(size, true), steps(s) {}
        inline bool operator==(const State &other) {
            if (steps != other.steps) {
                return false;
            }

            if (bulbs.size() != other.bulbs.size()) {
                return false;
            }

            for (size_t i(0); i < bulbs.size(); ++i) {
                if (bulbs[i] != other.bulbs[i] && !bulbs[i] != !other.bulbs[i]) {
                    return false;
                }
            }
            return true;
        }
        void flipAll(void) {
            for (vector<bool>::iterator i(bulbs.begin()); i != bulbs.end(); ++i) {
                *i = !*i;
            }
        }
        void flipOdd(void) {
            for (size_t i(0); i < bulbs.size(); i += 2) {
                bulbs[i] = !bulbs[i];
            }
        }
        void flipEven(void) {
            for (size_t i(1); i < bulbs.size(); i += 2) {
                bulbs[i] = !bulbs[i];
            }
        }
        void flipTriple(void) {
            for (size_t i(0); i < bulbs.size(); i += 3) {
                bulbs[i] = !bulbs[i];
            }
        }
    };

    void insertNonDuplicated(vector<State> &q, State &s) {
        for (vector<State>::iterator i(q.begin()); i != q.end(); ++i) {
            if (s == *i) {
                return;
            }
        }

        q.push_back(s);
    }
    int flipLights(int n, int m) {
        if (n == 0 || m == 0) {
            return 1;
        }
        /*
          For several reasons:
            1. flipAll + flipOdd = flipEven
               flipEven + flipAll = flipOdd
               flipEven + flipOdd = flipAll
            2. flipAll will not change the number of solutions
         */
        if (m > 3) {
            m = 3;
        }

        vector<State> queue;
        queue.push_back(State(n));
        size_t head(0);
        while (head < queue.size()) {
            State &cur(queue[head++]);

            State tmp(cur);
            tmp.steps++;
            if (tmp.steps > m) {
                continue;
            }

            tmp.flipAll();
            insertNonDuplicated(queue, tmp);
            tmp.flipAll();

            tmp.flipOdd();
            insertNonDuplicated(queue, tmp);
            tmp.flipOdd();

            tmp.flipEven();
            insertNonDuplicated(queue, tmp);
            tmp.flipEven();

            tmp.flipTriple();
            insertNonDuplicated(queue, tmp);
            tmp.flipTriple();
        }

        int ret(0);
        vector<State> answers;
        for (vector<State>::reverse_iterator i(queue.rbegin()); i != queue.rend(); ++i) {
            if (i->steps == m) {
                ret++;
            }
        }

        return ret;
    }
};
