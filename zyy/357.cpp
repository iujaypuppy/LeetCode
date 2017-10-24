class Solution {
  public:
    int countNumbersWithUniqueDigits(int n) {
        static int answers[] = {
            1, 10, 91, 739, 5275, 32491, 168571,
            712891, 2345851, 5611771, 8877691,
        };
        int count(sizeof(answers) / sizeof(answers[0]));
        return n < count ? answers[n] : answers[count - 1];
    }
};
