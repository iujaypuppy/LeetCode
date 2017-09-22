class Solution {
public:
    string convertToBase7(int num) {
        string res = (num >= 0) ? "" : "-";
        int convert_num(0), i(1);
        num = abs(num);
        while(num) {
            convert_num += (num % 7) * i;
            num /= 7;
            i *= 10;
        }
        res += to_string(convert_num);
        return res;
    }
};
