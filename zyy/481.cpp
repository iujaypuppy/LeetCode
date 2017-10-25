class Solution {
  public:
    class Stream {
      private:
        vector<int> s;
        int base;
      public:
        Stream(void): base(0) {}
        void push(int n) {
            s.push_back(n);
        }
        int &operator[](int i) {
            i -= base;
            s.erase(s.begin(), s.begin() + i);
            base += i;
            return *s.begin();
        }
        int size(void) const {
            return base + s.size();
        }
    };
    int magicalString(int n) {
        if (n == 0) {
            return 0;
        }
        Stream seq;
        seq.push(1);
        seq.push(2);
        seq.push(2);
        int sym(1), ret(1);
        for (int i(2); i < n; i++) {
            if (seq[i] == 1) {
                ret++;
            }
            for (int j(0); j < seq[i]; j++) {
                seq.push(sym);
            }
            if (sym == 1) {
                sym = 2;
            } else {
                sym = 1;
            }
        }

        return ret;
    }
};
