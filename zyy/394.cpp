class Solution {
  public:
    string decodePlainText(string::iterator begin, string::iterator end) {
        string ret;
        while (begin != end && isalpha(*begin)) {
            ret += *begin;
            begin++;
        }

        return ret;
    }
    string decodeString(string::iterator begin, string::iterator end) {
        if (begin == end) {
            return "";
        }

        stack<string::iterator> s;
        string ret(decodePlainText(begin, end));
        string::iterator b(begin + ret.length());
        for (string::iterator i(begin); i != end; i++) {
            if (*i == '[') {
                s.push(i);
                continue;
            }
            if (*i == ']') {
                string::iterator left(s.top());
                s.pop();
                if (s.empty()) {
                    int k(atoi(string(b, left).c_str()));
                    string sub(decodeString(left + 1, i));
                    for (int i(0); i < k; i++) {
                        ret += sub;
                    }
                    string plain(decodePlainText(i + 1, end));
                    ret += plain;
                    b = i + plain.length() + 1;
                    continue;
                }
            }
        }

        return ret;
    }
    string decodeString(string s) {
        return decodeString(s.begin(), s.end());
    }
};
