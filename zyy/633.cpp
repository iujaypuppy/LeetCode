class Solution {
  public:
    bool judgeSquareSum(int c) {
        for (int i(0); i <= sqrt(c / 2); i++) {
            int jSquare(c - i * i), j(sqrt(jSquare));
            if (jSquare == j * j) {
                return true;
            }
        }
        return false;
    }
};
