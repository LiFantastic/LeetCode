/*============================================================
Problem: Repeated DNA Sequences
==============================================================
All DNA is composed of a series of nucleotides abbreviated as 
A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, 
it is sometimes useful to identify repeated sequences within 
the DNA.

Write a function to find all the 10-letter-long sequences 
(substrings) that occur more than once in a DNA molecule.

For example,
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
Return:
["AAAAACCCCC", "CCCCCAAAAA"].
============================================================*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    	unordered_map<int, int> hashTable;
    	vector<string> res;
    	int t = 0, i = 0, length = s.size();
    	while (i < 9)
        	t = t << 3 | s[i++] & 7;  // 7: 0111, use last three digits for coding
    	while (i < length) {
        	if (hashTable[t = t<<3&0x3FFFFFFF|s[i++]&7]++ == 1)  //3FFFFFFF: 0011...11, 30 digits for 10 letters
        		res.push_back(s.substr(i-10, 10));
        }
    	return res;
}
};