class Solution {
  public:
    bool isVowel(const char &c) {
        static const string &VOWELS("aeiouAEIOU");
        for (string::const_iterator i(VOWELS.begin());
             i != VOWELS.end(); i++) {
            if (c == *i) {
                return true;
            }
        }

        return false;
    }

    void reverseVowels(vector<string::iterator> &vowels) {
        if (vowels.empty()) {
            return;
        }
        vector<string::iterator>::iterator begin(vowels.begin()), end(vowels.end() - 1);
        while (begin < end) {
            char tmp(**begin);
            **begin = **end;
            **end = tmp;
            begin++;
            end--;
        }
    }

    string reverseVowels(string s) {
        vector<string::iterator> vowels;
        for (string::iterator i(s.begin()); i != s.end(); i++) {
            if (isVowel(*i)) {
                vowels.push_back(i);
            }
        }

        reverseVowels(vowels);
        return s;
    }
};
