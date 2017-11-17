class Solution {
  public:
    int maximumSwap(int num) {
        string str(to_string(num));
        for (string::iterator i(str.begin()); i != str.end(); i++) {
            string::iterator k(i);
            for (string::iterator j(i + 1); j != str.end(); j++) {
                if (*j >= *k) {
                    k = j;
                }
            }
            if (*k > *i) {
                char tmp(*i);
                *i = *k;
                *k = tmp;
                return atoi(str.c_str());
            }
        }
        return num;
    }
};
