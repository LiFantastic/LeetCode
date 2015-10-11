/*============================================================
Problem: Length of Last Word
==============================================================
Given a string s consists of upper/lower-case alphabets and 
empty space characters ' ', return the length of last word in 
the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of 
non-space characters only.

For example, 
Given s = "Hello World",
return 5.
============================================================*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size(), res = 0, i = len-1;
        while (s[i]==' ') i--;
        for ( ; i>=0; i--) {
            if (s[i]!=' ')
                res++;
            else
                break;
        }
        return res;
    }
};