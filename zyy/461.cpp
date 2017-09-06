class Solution {
  public:
    int hammingDistance(int x, int y) {
        /* This step uses xor operator to get all different bit positions. */
        unsigned int diff((unsigned int)x ^ (unsigned int)y);

        /*
          This step calculates the number of different bit positions.
          It seems confusing but uses a classic algorithm principle: divdie and conquer.
          Assume we want to count the number of ones in a 8-bit number in binary format:
              |0|1|0|1|1|1|0|1|
          The idea is that, we calculate the ones in every two bits:
              |0|1|0|1|1|1|0|1| -> |0+1|0+1|1+1|0+1| -> |01|01|10|01|
          the final number |01|01|10|01|, every cell composed of two bits means how many
          ones are there in this position of original number, e.g.: in the third cell, it
          is "10", which means in orginal number, there are two ones in the 5th and 6th bit
          position.
          Similarly, we can get how many bits are 1 in every four bits:
              |01|01|10|01| -> |01+01|10+01| -> |0010|0011|
          and the two cells mean that, in the first four bits of original number, there are
          two ones, and in the last four bits there are three.
          Finally, we can get how many bits are 1 in all the eight bits:
              |0010|0011| -> |0010+0011| -> |00000101| = 5

          In the following code, 0x55555555 is 01010101010101010101010101010101 in binary,
          by adding (diff & 0x55555555) and ((diff >> 1) & 0x55555555), we get the ones in
          every two bits. Similarly,
              0x33333333 -> 00110011001100110011001100110011
              0x0F0F0F0F -> 00001111000011110000111100001111
              0x00FF00FF -> 00000000111111110000000011111111
              0x0000FFFF -> 00000000000000001111111111111111
         */
        diff = (diff & 0x55555555) + ((diff >> 1) & 0x55555555);
        diff = (diff & 0x33333333) + ((diff >> 2) & 0x33333333);
        diff = (diff & 0x0F0F0F0F) + ((diff >> 4) & 0x0F0F0F0F);
        diff = (diff & 0x00FF00FF) + ((diff >> 8) & 0x00FF00FF);
        diff = (diff & 0x0000FFFF) + ((diff >> 16) & 0x0000FFFF);
        return (int)diff;
    }
};
