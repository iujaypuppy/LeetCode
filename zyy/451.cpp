class Solution {
  public:
    class Gadgets {
      private:
        static const size_t TOTAL = 256;
        int count[TOTAL];
        class Char {
          private:
            char c;
            int count;
          public:
            string toString(void) {
                return string(count, c);
            }
            Char(const char ch, const int number): c(ch), count(number) {}
            inline bool operator<(const Char &other) const { return count > other.count; }
        };
      public:
        Gadgets(const string &str = "") {
            for (size_t i(0); i < TOTAL; ++i) {
                count[i] = 0;
            }

            for (string::const_iterator i(str.begin()); i != str.end(); ++i) {
                count[(unsigned char)*i]++;
            }
        }

        string frequencySort(void) const {
            vector<Char> sorted;
            for (size_t i(0); i < TOTAL; ++i) {
                if (count[i] > 0) {
                    sorted.push_back(Char((char)i, count[i]));
                }
            }
            sort(sorted.begin(), sorted.end());
            string ret;
            for (vector<Char>::iterator i(sorted.begin()); i != sorted.end(); ++i) {
                ret += i->toString();
            }

            return ret;
        }
    };
    string frequencySort(string s) {
        Gadgets gadgets(s);
        return gadgets.frequencySort();
    }
};
