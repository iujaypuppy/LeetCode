class Solution {
  public:
    class Gadgets {
      private:
        static const size_t TOTAL = 26;
        int count[TOTAL];
      public:
        Gadgets(const string &str) {
            for (size_t i(0); i < TOTAL; i++) {
                count[i] = 0;
            }

            for (string::const_iterator i(str.begin()); i != str.end(); i++) {
                count[(size_t)*i - 'a']++;
            }
        }

        void remove(char c, int n) {
            count[(size_t)c - 'a'] -= n;
        }

        void remove(const string &str, int n) {
            for (string::const_iterator i(str.begin()); i != str.end(); i++) {
                remove(*i, n);
            }
        }
        int get(char c) const { return count[(size_t)c - 'a']; }
    };

    void cat(string &s, string t, int times) {
        for (int i(0); i < times; i++) {
            s += t;
        }
    }

    string originalDigits(string s) {
        Gadgets unsorted(s);
        vector<int> count(10);
        count[0] = unsorted.get('z');
        unsorted.remove("zero", count[0]);

        count[2] = unsorted.get('w');
        unsorted.remove("two", count[2]);

        count[4] = unsorted.get('u');
        unsorted.remove("four", count[4]);

        count[1] = unsorted.get('o');
        unsorted.remove("one", count[1]);

        count[6] = unsorted.get('x');
        unsorted.remove("six", count[6]);

        count[7] = unsorted.get('s');
        unsorted.remove("seven", count[7]);

        count[5] = unsorted.get('v');
        unsorted.remove("five", count[5]);

        count[8] = unsorted.get('g');
        unsorted.remove("eight", count[8]);

        count[3] = unsorted.get('t');
        unsorted.remove("three", count[3]);

        count[9] = unsorted.get('i');
        unsorted.remove("nine", count[9]);

        string ret;
        for (int i(0); i < 10; i++) {
            for (int j(0); j < count[i]; j++) {
                ret += string(1, '0' + i);
            }
        }

        return ret;
    }
};
