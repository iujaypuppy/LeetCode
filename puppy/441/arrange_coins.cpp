class Solution {
public:
    int arrangeCoins(int n) {
        // (x+1)*x/2 = n => x = (-1 + sqrt(1+8*n))/2
        double x = (sqrt(((double)n) *8 + 1 ) - 1) / 2;
        return (int)x;
    }
};
