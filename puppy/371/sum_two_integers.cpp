class Solution {
public:
    int getSum(int a, int b) {
        int shift = 0;
        int bit_carry = 0;
        int sum = 0;
        unsigned int unsign_a(a), unsign_b(b);
        while ((unsign_a || unsign_b || bit_carry) && (shift < 32)) {
            int bit_a = unsign_a & 0x01;
            int bit_b = unsign_b & 0x01;
            int bit_sum = bit_a ^ bit_b ^ bit_carry;
            if ((bit_a & bit_b) || (bit_a & bit_carry) || (bit_b & bit_carry)) {
                bit_carry = 1;
            } else
            {
                bit_carry = 0;
            }
            sum = sum | (bit_sum << shift);
            //TODO: how to increse self without using ++;
            shift++; 
            unsign_a = unsign_a >> 1;
            unsign_b = unsign_b >> 1;   
        }
        return sum;
    }
};
