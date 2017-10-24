class Solution {
  public:
    class Fraction {
      private:
        int numerator;
        int denominator;
        static int gcd(int a, int b) {
            if (a > b) {
                return gcd(b, a);
            }

            if (a == 0) {
                return b;
            }

            return gcd(b - a, a);
        }
        void reduce(void) {
            if (denominator < 0) {
                numerator *= -1;
                denominator *= -1;
            }

            int n(gcd(abs(numerator), denominator));
            numerator /= n;
            denominator /= n;
        }
      public:
        Fraction(int n = 0, int d = 1): numerator(n), denominator(d) {
            reduce();
        }
        string toString(void) const {
            return to_string(numerator) + "/" + to_string(denominator);
        }
        const Fraction operator+(const Fraction &other) const {
            return Fraction(numerator * other.denominator +
                            other.numerator * denominator,
                            denominator * other.denominator);
        }
        Fraction &operator+=(const Fraction &rhs) {
            *this = *this + rhs;
            return *this;
        }
        static bool produceFraction(string &expression,
                                    Fraction &ret) {
            if (expression.empty()) {
                return false;
            }

            static const int BASE(10);
            char *str;
            long n(strtol(expression.c_str(), &str, BASE)), d(1);
            if (*str == '/') {
                d = strtol(str + 1, &str, BASE);
            }

            expression = string(str);
            ret = Fraction(n, d);

            return true;
        }
    };

    string fractionAddition(string expression) {
        Fraction result, tmp;
        while (Fraction::produceFraction(expression, tmp)) {
            result += tmp;
        }
        return result.toString();
    }
};
