class Solution {
public:
    int findComplement(int num) {
        int complement = 0, i = 0;
        while(num) {
            complement += ((num ^ 0x01) & 0x01) << i;
            num = num >> 1;
            i++;
        }
        return complement;
    }
};
