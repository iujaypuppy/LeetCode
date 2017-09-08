class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            if (same_row_alphabets(*iter)) {
                res.push_back(*iter);
            }
        }
        return res;
    }
    
    bool same_row_alphabets(string word) {
        int flag = 0;
        for (int i = 0; i < word.size(); i++) {
            switch (word[i]) {
                case 'q' : case 'w': case 'e': case 'r': case 't': case 'y': case 'u': case 'i': case 'o': case'p' :
                    flag = flag | 0x01;
                    break;
                case 'a': case 's': case 'd': case 'f': case 'g': case 'h': case 'j': case 'k': case 'l' :
                    flag = flag | 0x10;
                    break;
                case 'z': case 'x': case 'c': case 'v': case 'b': case 'n': case 'm' :
                    flag = flag | 0x100;
                    break;
                default :
                    break;
            }
        }
        return (flag == 0x01 || flag == 0x10 || flag == 0x100);
    }
};
