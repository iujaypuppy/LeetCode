class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t len(strs.size());
        if (strs.size() == 0) {
            return "";
        }
        string res(strs[0]);
        for (size_t i(1); i < len; i++) {
            string cur("");
            size_t j(0);
            while (j < res.size() && j < strs[i].size()) {
                if (res[j] == strs[i][j]) {
                    cur += res[j];
                } else {
                    res = cur;
                    break;
                }
                j++;
            }
            res = cur;
            if (res.empty()) {
                break;
            }
        }
        return res;
    }
};
