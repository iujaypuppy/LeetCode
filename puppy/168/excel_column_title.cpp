class Solution {
public:
    string convertToTitle(int n) {
        const static int BASE = 26;
        
        string res("");
        while (n) {
            n--;
            char c = 'A' + ((n % BASE));
            res = c + res;
            n /= BASE;
        }
        return res;
    }
};
