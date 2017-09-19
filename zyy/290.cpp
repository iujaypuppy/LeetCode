class Solution {
  public:
    /* Borrow code from problem 205 */
    class BindingMap {
      private:
        static const int M = 256;
        char map[M];
        char reverseMap[M];
        bool mapped[M];
      public:
        BindingMap(void) {
            for (int i(0); i < M; i++) {
                mapped[i] = false;
            }
        }

        bool bind(char a, char b) {
            unsigned char ua(a), ub(b);
            if (mapped[ub] && reverseMap[ub] != a) {
                return false;
            }
            mapped[ub] = true;
            reverseMap[ub] = a;
            map[ua] = b;

            return true;
        }

        bool bind(const string &s, const string &t) {
            for (size_t i(0); i < s.size(); i++) {
                if (!bind(s[i], t[i])) {
                    return false;
                }
            }

            return true;
        }

        string &transfer(string &s) {
            for (string::iterator i(s.begin()); i != s.end(); i++) {
                *i = map[(unsigned char)*i];
            }
            return s;
        }
    };
    bool isIsomorphic(string s, string t) {
        BindingMap map;

        return map.bind(s, t) && map.transfer(s) == t;
    }
    /* This problem */
    class Words {
      private:
        vector<string> words;
      public:
        Words(const string &s) {
            string::const_iterator i(s.begin());
            while (i != s.end()) {
                while (i != s.end() && isspace(*i)) {
                    i++;
                }

                string word;
                while (i != s.end() && !isspace(*i)) {
                    word += *i;
                    i++;
                }
                if (!word.empty()) {
                    words.push_back(word);
                }
            }
        }

        string pattern(void) {
            static const int MAX_PATTERN = 26;
            string pattern;
            string map[MAX_PATTERN];
            for (vector<string>::iterator i(words.begin()); i != words.end(); i++) {
                bool match(false);
                for (int j(0); j < MAX_PATTERN; j++) {
                    if (map[j] == *i) {
                        pattern += string(1, j + 'a');
                        match = true;
                        break;
                    }
                }

                if (!match) {
                    for (int j(0); j < MAX_PATTERN; j++) {
                        if (map[j].empty()) {
                            map[j] = *i;
                            pattern += string(1, j + 'a');
                            match = true;
                            break;
                        }
                    }
                }

                if (!match) {
                    pattern += string(1, 'A');
                }
            }

            return pattern;
        }
    };
    bool wordPattern(string pattern, string str) {
        Words words(str);
        return isIsomorphic(words.pattern(), pattern);
    }
};
