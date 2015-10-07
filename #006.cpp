/*============================================================
Problem: ZigZag Conversion
==============================================================
The string "PAYPALISHIRING" is written in a zigzag pattern on 
a given number of rows like this: (you may want to display 
this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR" 

Write the code that will take a string and make this conversion 
given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
============================================================*/
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if (len==0 || numRows<2) return s;
        
        string res = "";
        int cycleLen = 2*numRows-2; // the length of cycle
        for (int i=0; i<numRows; i++) {
            for (int j=i; j<len; j+=cycleLen) {
                res += s[j];
                if (i > 0 && i < numRows-1) { // for the middle lines, another char is added
                    int k = j+cycleLen-2*i;
                    if (k < len) {
                        res += s[k];
                    }
                }
            }
        }
        return res;
    }
};