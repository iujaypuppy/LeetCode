class Solution {
  public:
    class Expression {
      private:
        class Token {
          public:
            union {
                char op;
                int oprand;
            } symbol;
            bool isOp;
            string str;
            Token(int n = 0): isOp(false) {
                symbol.oprand = n;
            }
            Token(string s): str(s) {
                switch (s[0]) {
                    case '+':
                    case '-':
                    case '*':
                        isOp = true;
                        symbol.op = s[0];
                        break;
                    default:
                        isOp = false;
                        symbol.oprand = atoi(s.c_str());
                        break;
                }
            }
        };
        bool parseToken(string &s, Token &ret) {
            while (!s.empty() && isspace(s[0])) {
                s.erase(s.begin());
            }

            if (s.empty()) {
                return false;
            }

            string::iterator end(s.begin());
            if (isdigit(s[0])) {
                while (end != s.end() && isdigit(*end)) {
                    end++;
                }
            } else {
                while (end != s.end() && !isdigit(*end)) {
                    end++;
                }
            }
            ret = Token(string(s.begin(), end));
            s.erase(s.begin(), end);
            return true;
        }
        vector<Token> oprands;
        vector<Token> ops;
      public:
        Expression(string s) {
            if (s[0] == '+' || s[0] == '-') {
                oprands.push_back(Token(0));
            }
            Token ret;
            while (parseToken(s, ret)) {
                if (ret.isOp) {
                    ops.push_back(ret);
                } else {
                    oprands.push_back(ret);
                }
            }
        }
        size_t opSize() const { return ops.size(); }
        int firstOprand(void) const { return oprands[0].symbol.oprand; }
        string firstExpression(void) const { return oprands[0].str; }
        Expression apply(size_t i) {
            Expression ret(*this);
            int left(oprands[i].symbol.oprand), right(oprands[i + 1].symbol.oprand);
            int result(0);
            switch (ops[i].symbol.op) {
                case '+':
                    result = left + right;
                    break;
                case '-':
                    result = left - right;
                    break;
                case '*':
                    result = left * right;
                    break;
            }
            ret.oprands[i] = Token(result);
            ret.oprands[i].str = "(" + oprands[i].str + ops[i].str + oprands[i + 1].str + ")";
            ret.oprands.erase(ret.oprands.begin() + i + 1);
            ret.ops.erase(ret.ops.begin() + i);
            return ret;
        }
    };

    void diffWaysToCompute(Expression exp, vector<int> &ret, vector<string> &set) {
        if (exp.opSize() == 0) {
            string str(exp.firstExpression());
            for (vector<string>::iterator i(set.begin()); i != set.end(); i++) {
                if (str == *i) {
                    return;
                }
            }
            set.push_back(str);
            ret.push_back(exp.firstOprand());
            return;
        }

        for (size_t i(0); i < exp.opSize(); i++) {
            diffWaysToCompute(exp.apply(i), ret, set);
        }
    }

    vector<int> diffWaysToCompute(string input) {
        Expression exp(input);
        vector<int> ret;
        vector<string> set;
        diffWaysToCompute(exp, ret, set);
        return ret;
    }
};
