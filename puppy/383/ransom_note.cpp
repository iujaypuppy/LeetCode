class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        
        string::iterator j(magazine.begin());
        for (string::iterator i(ransomNote.begin()); i != ransomNote.end(); i++) {
            bool is_find = false;
            while (j != magazine.end()) {
                if (*i == *j) {
                    j++;
                    is_find = true;
                    break;
                }
                j++;
            }
            if (!is_find) {
                return false;
            }
        }
        return true;
    }
};
