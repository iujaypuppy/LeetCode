class Solution {
  public:
    string toUpper(const string& word) {
        string result;
        for (string::const_iterator c(word.begin()); c != word.end(); c++) {
            result += toupper(*c);
        }
        return result;
    }
    string toLower(const string& word) {
        string result;
        for (string::const_iterator c(word.begin()); c != word.end(); c++) {
            result += tolower(*c);
        }
        return result;
    }
    bool detectCapitalUse(string word) {
        string upper(toUpper(word));
        string lower(toLower(word));
        string normal(lower);

        if (!normal.empty()) {
            *normal.begin() = toupper(*normal.begin());
        }

        return word == upper || word == lower || word == normal;
    }
};
