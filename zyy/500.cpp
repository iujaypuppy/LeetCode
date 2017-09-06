class Solution {
  public:
    vector<string> findWords(vector<string>& words) {
        int row[256];
        char *keyboard[3] = { "qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM" };

        for (int i(0); i < 3; i++) {
            size_t length = strlen(keyboard[i]);
            for (size_t j(0); j < length; j++) {
                row[keyboard[i][j]] = i;
            }
        }

        vector<string> result;

        for (vector<string>::iterator i(words.begin()); i != words.end(); i++) {
            string &word(*i);
            if (word.empty()) {
                result.push_back(word);
                continue;
            }
            int thisRow(row[*word.begin()]);
            bool pass(true);
            for (string::iterator j(word.begin()); j != word.end(); j++) {
                if (row[*j] != thisRow) {
                    pass = false;
                    break;
                }
            }

            if (pass) {
                result.push_back(word);
            }
        }

        return result;
    }
};
