/*============================================================
Problem: Number of 1 Bits
==============================================================
Write a function that takes an unsigned integer and returns 
the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 
00000000000000000000000000001011, so the function should return 3.
============================================================*/
class Solution {
private:
	const uint32_t mask01  = 0x55555555; //binary: 0101...
    const uint32_t mask02  = 0x33333333; //binary: 00110011..
    const uint32_t mask04  = 0x0f0f0f0f; //binary:  4 zeros,  4 ones ...
    const uint32_t mask08  = 0x00ff00ff; //binary:  8 zeros,  8 ones ...
    const uint32_t mask16 = 0x0000ffff; //binary: 16 zeros, 16 ones ...
public:
    int hammingWeight(uint32_t n) {
        uint32_t res = n;
        res = (res & mask01) + ((res >>  1) & mask01); //put count of each  2 bits into those  2 bits 
        res = (res & mask02) + ((res >>  2) & mask02); //put count of each  4 bits into those  4 bits 
        res = (res & mask04) + ((res >>  4) & mask04); //put count of each  8 bits into those  8 bits 
        res = (res & mask08) + ((res >>  8) & mask08); //put count of each 16 bits into those 16 bits 
        res = (res & mask16) + ((res >> 16) & mask16); //put count of each 32 bits into those 32 bits 
        return res;
    }
};