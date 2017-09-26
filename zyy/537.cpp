class Solution {
  public:
    void splitComplexNumber(const string &c, long &real, long &imaginary) {
        const char *str(c.c_str());
        char *end;
        real = strtol(str, &end, 10);

        while (end[0] != '+') {
            end++;
        }
        end++;

        imaginary = strtol(end, NULL, 10);
    }
    string complexNumberMultiply(string a, string b) {
        long aReal, aImaginary, bReal, bImaginary;
        splitComplexNumber(a, aReal, aImaginary);
        splitComplexNumber(b, bReal, bImaginary);

        long real(aReal * bReal - aImaginary * bImaginary);
        long imaginary(aReal * bImaginary + bReal * aImaginary);
        return to_string(real) + "+" + to_string(imaginary) + "i";
    }
};
