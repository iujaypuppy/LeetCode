class Solution {
public:
    int romanToInt(string s) {
        static map<char, int> romanTable;
        romanTable['I'] = 1;
        romanTable['X'] = 10;
        romanTable['C'] = 100;
        romanTable['M'] = 1000;
        romanTable['V'] = 5;
        romanTable['L'] = 50;
        romanTable['D'] = 500;
        
        int res(0);
        size_t len(s.size());
        for (size_t i(0); i < len; i++) {
            int minus(0), current(romanTable[s[i]]);
            res += current;
            if (i >= 1 && current > romanTable[s[i - 1]]) {
                minus += romanTable[s[i - 1]];
            } 
            if (i >= 2 && current > romanTable[s[i - 2]]) {
                minus += romanTable[s[i - 2]];
            } 
            if (i >= 3 && current > romanTable[s[i - 3]]) {
                minus += romanTable[s[i - 3]];
            } 
            res -= minus << 1;
        }
        return res;
    }
};
