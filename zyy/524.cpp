class Solution {
  public:
    class CharNode {
      private:
        vector<int> n;
        char c;
      public:
        CharNode(char ch = '\0'): c(ch) {
            static const int WIDTH(26);
            n.resize(WIDTH, -1);
        }
        int &next(char ch) {
            return n[(size_t)(ch - 'a')];
        }
        char me(void) const { return c; }
    };

    static bool cmp(const string &a, const string &b) {
        return a.length() > b.length() ||
                (a.length() == b.length() && a < b);
    }

    bool walk(vector<CharNode> &s, const string &w) {
        int index(0);
        for (string::const_iterator i(w.begin()); i != w.end(); i++) {
            if (index == -1) {
                return false;
            }
            index = s[index].next(*i);
        }

        return index != -1;
    }

    string findLongestWord(string s, vector<string>& d) {
        if (s.empty()) {
            return "";
        }
        vector<CharNode> str;
        for (int i((int)s.length()); i >= 0; i--) {
            str.insert(str.begin(), i == 0 ? CharNode() : CharNode(s[i - 1]));

            if (str.size() == 1) {
                continue;
            }
            for (char c('a'); c <= 'z'; c++) {
                if (c == str[1].me()) {
                    str[0].next(c) = i + 1;
                    continue;
                }
                str[0].next(c) = str[1].next(c);
            }
        }

        sort(d.begin(), d.end(), cmp);
        for (vector<string>::iterator i(d.begin()); i != d.end(); i++) {
            if (walk(str, *i)) {
                return *i;
            }
        }
        return "";
    }
};
