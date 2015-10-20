/*============================================================
Problem: Bitwise AND of Numbers Range
==============================================================
Given a range [m, n] where 0 <= m <= n <= 2147483647, return 
the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
============================================================*/
class Solution { 
public:
    int rangeBitwiseAnd(int m, int n) {
        int mask = ~0;  // mask: all ones
        while (mask && (m & mask) != (n & mask)) 
        	mask <<= 1; 
        return m & mask;
    }
    /*  5: 01 01  there must be at least one 0 at last positions where m differs from n
    	6: 01 10
    	7: 01 11
      res: 01 00
	*/
};