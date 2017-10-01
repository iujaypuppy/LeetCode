class Solution {
public:
    int countSegments(string s) {
        int sum(0);
        bool is_segment = false;
        for (size_t i(0); i < s.size(); i++) {
            if (s[i] != ' ') {
                is_segment = true;
            } else {
                sum += (is_segment) ? 1 : 0;
                is_segment = false;
            }
        }
        sum += (is_segment) ? 1 : 0;
        return sum;
    }
};
