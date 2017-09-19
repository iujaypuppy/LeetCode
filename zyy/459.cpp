class Solution {
  public:
    void stringMultiply(const string &pattern, size_t times, string &result) {
        if (times == 0) {
            result = "";
            return;
        }

        stringMultiply(pattern, times / 2, result);
        result += result;
        if (times % 2 != 0) {
            result += pattern;
        }
    }

    bool repeatedSubstringPattern(string s) {
        string head, tail;
        string::iterator h(s.begin());
        string::reverse_iterator t(s.rbegin());
        while (head.size() + tail.size() <= s.size() &&
               h != s.end() && t != s.rend()) {
            head += *h;
            tail = *t + tail;
            h++;
            t++;
            if (head != tail || s.size() % head.size() != 0 ||
                s.size() == head.size()) {
                continue;
            }

            string str;
            /*
              str = head * (s.size() / head.size())
              String multiplication is defined as duplication of string.
              E.g.: "a" * 3 = "aaa"
            */
            stringMultiply(head, s.size() / head.size(), str);
            if (s == str) {
                return true;
            }
        }

        return false;
    }
};
