class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        } 
        int pre(1), next(2);
        for (int i(3); i <= n; i++ ) {
            int current = pre + next;
            pre = next;
            next = current;
        }
        return next;
    }
};
