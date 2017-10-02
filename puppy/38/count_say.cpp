class Solution {
public:
    string countAndSay(int n) {
        string pre("1"), cur("");
        int count(1);
        while (count < n) {
            cur = "";
            int num(1);
            for (size_t i(1); i < pre.size(); i++) {
                if (pre[i] != pre[i - 1]) {
                    cur += to_string(num);
                    cur += pre[i - 1];
                    num = 1;
                } else {
                    num++; 
                }
            }
            cur += to_string(num);
            cur += pre[pre.size() - 1];
            pre = cur;
            count++;
        }
        return pre;
    }
};
