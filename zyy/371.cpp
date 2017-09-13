class Solution {
  public:
    unsigned int addOne(unsigned int n) {
        return (n & 1) ? (addOne(n >> 1) << 1) : (n | 1);
    }
    int getSum(int a, int b) {
        unsigned int ua(a), ub(b), carry(0), pos(0), result(0);
        while (ua != 0 || ub != 0 || pos != sizeof(result) << 3) {
            unsigned int bit((ua ^ ub ^ carry) & 1);
            carry = (ua & ub) | (ua & carry) | (ub & carry);
            result |= bit << pos;
            ua >>= 1;
            ub >>= 1;
            pos = addOne(pos);
        }

        return (int)result;
    }
};
