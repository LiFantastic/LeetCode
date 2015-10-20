/*============================================================
Problem: Reverse Bits
==============================================================
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 
00000010100101000001111010011100), return 964176192 
(represented in binary as 00111001011110000010100101000000).
============================================================*/
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		n = ((n<<16) | (n>>16));                         //swap [31:16]<=>[15:0]
   		n = ((n&0x00ff00ff)<< 8 | (n&0xff00ff00)>> 8);   //swap [31:24]<=>[23:16] , [15:8]<=>[7:0]
   		n = ((n&0x0f0f0f0f)<< 4 | (n&0xf0f0f0f0)>> 4);   //swap ...
   		n = ((n&0x33333333)<< 2 | (n&0xcccccccc)>> 2);   //swap ...
   		n = ((n&0x55555555)<< 1 | (n&0xaaaaaaaa)>> 1);   //swap ...
   		return n;    
	}
};