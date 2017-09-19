class Solution {
  public:
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
};
