class Solution {
public:
    string reverseVowels(string s) {
        if(s.size() <= 1) {
            return s;
        }
        size_t i(0), j(s.size() - 1);
        while (i < j) {
            if (is_vowel(s[i]) && is_vowel(s[j])) {
                s[i] = s[i] ^ s[j];
                s[j] = s[i] ^ s[j];
                s[i] = s[i] ^ s[j];
                i++;
                j--;
            } else if (is_vowel(s[i])) {
                j--;
            } else if (is_vowel(s[j])) {
                i++;
            } else {
                i++;
                j--;
            }
        }
        return s;
    }
    
    bool is_vowel(char c) {
        bool res;
        switch (tolower(c)) {
            case 'a' :
            case 'i' :
            case 'o' :
            case 'u' :
            case 'e' :
                res = true;
                break;
            default:
                res = false;
                break;
        }
        return res;
    }
};
