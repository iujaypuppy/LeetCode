class Solution {
  public:
    bool checkPair(char left, char right) {
        return (left == '(' && right == ')') ||
                (left == '[' && right == ']') ||
                (left == '{' && right == '}') ||
                (left == '<' && right == '>');
    }
    bool isValid(string s) {
        stack<char> brackets;
        for (string::iterator i = s.begin(); i != s.end(); i++) {
            switch (*i) {
                case '{': case '(': case '[': case '<':
                    brackets.push(*i);
                    break;
                case '}': case ')': case ']': case '>':
                    if (brackets.empty() || !checkPair(brackets.top(), *i)) {
                        return false;
                    }
                    brackets.pop();
                    break;
                default:
                    break;
            }
        }
        return brackets.empty();
    }
};
