class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) {
            return false;
        }
        
        int sum(1), sqrtNum(sqrt(num));
        for (int i(2); i <= sqrtNum; i++) {
            if (num % i == 0) {
                sum += (i + num / i);
            }
        }
        if (sqrtNum * sqrtNum == num) {
            sum -= sqrtNum;
        }
        return num == sum;
    }
};
