class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for (string::iterator i(s.begin()); i != s.end(); i++) {
            if (*i == '(' || *i == '{' || *i == '[') {
                brackets.push(*i);
            } else {
                if (brackets.empty() || !isClosed(brackets.top(), *i)) {
                    return false;
                } else {
                    brackets.pop();
                }
            }
        }
        return brackets.empty();
    }
    
    bool isClosed(char open, char close) {
        bool res = false;
        switch (open) {
            case '[' :
                res = close == ']';
                break;
            case '{' :
                res = close == '}';
                break;
            case '(' :
                res = close == ')';
                break;
            default:
                break;
        }
        return res;
    }
};
