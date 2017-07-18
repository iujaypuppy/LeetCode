class Solution {
  public:
    string convert(string s, int numRows) {
        char **map = new char *[numRows];
        for (int i = 0; i < numRows; i++) {
            map[i] = new char[s.length()];
            for (size_t j = 0; j < s.length(); j++) {
                map[i][j] = '\0';
            }
        }

        /* coordinate */
        int x(0), y(0);
        /*
          marching down is zig, marching up is zag:
                   Z       I
                   H     E L
            zig -> A   I   U
                   N J <- zag
                   G
         */
        bool zig(true);

        if (numRows <= 1) {
            return s;
        }

        for (string::iterator i = s.begin(); i != s.end(); i++) {
            map[x][y] = *i;
            if (zig) {
                /* zig */
                if (x == numRows - 1) {
                    /* it's time for zag phase */
                    x--;
                    y++;
                    zig = false;
                } else {
                    x++;
                }
            } else {
                /* zag */
                if (x == 0) {
                    /* it's time for zig phase */
                    x++;
                    zig = true;
                } else {
                    x--;
                    y++;
                }
            }
        }

        string ret = "";

        for (int i = 0; i < numRows; i++) {
            for (size_t j = 0; j < s.length(); j++) {
                if (map[i][j]) {
                    ret += map[i][j];
                }
            }
        }
        return ret;
    }
};
