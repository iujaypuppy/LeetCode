class Solution {
  public:
    class History {
      private:
        /* 8-bit characters */
        static const int CHAR_SIZE = 256;
        int history[CHAR_SIZE];
      public:
        History(void) {
            for (int i = 0; i < CHAR_SIZE; i++) {
                history[i] = -1;
            }
        }
        bool appeared(char c) const {
            unsigned char index = (unsigned char)c;
            if (history[index] != -1) {
                return true;
            }
            return false;
        }
        /* clear hisotry for character whose position is before c */
        void clear(char c) {
            unsigned char index = (unsigned char)c;
            for (int i = 0; i < CHAR_SIZE; i++) {
                if (history[i] < history[index]) {
                    history[i] = -1;
                }
            }
            history[index] = -1;
        }
        int& operator[](char c) {
            unsigned char index = (unsigned char)c;
            return history[index];
        }
    };

    int lengthOfLongestSubstring(string s) {
        History history;
        /*
          maximum length of solution,
          current length of solution,
          start position of current solution
         */
        int maximum(0), current(0), start(0);
        for (string::iterator i = s.begin(); i != s.end(); i++) {
            char c = *i;
            int index = i - s.begin();
            if (!history.appeared(c)) {
                current++;
            } else {
                /* this character appeared at history[c] index in string s */

                // record maximal length
                if (current > maximum) {
                    maximum = current;
                }

                // remove the substring from current start to the last
                // occurred position of duplicated character
                start = history[c] + 1;
                history.clear(c);
                current = index - start + 1;
            }
            history[c] = index;
        }

        /* corner case: last substring */
        if (current > maximum) {
                maximum = current;
        }

        return maximum;
    }
};
