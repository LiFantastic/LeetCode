/*============================================================
Problem: Roman to Integer
==============================================================
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
============================================================*/
class Solution {
private:
    int getRomanValue(char c) {
        switch(c) {
           	case 'I': return 1; 
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default : return 0;
        }
    }
public:
    int romanToInt(string s) {
        if (s.size() < 1) return 0;
        int res = 0;
        int sub = getRomanValue(s[0]);
        int lastV = sub;
        for (int i=1; i<s.size(); i++) {
            char curC = s[i];
            int curV = getRomanValue(curC);
            if (curV==lastV) 
                sub += curV;
            else if (curV < lastV) {
                res += sub;
                sub = curV;
            } 
            else
                sub = curV - sub;

            lastV = curV;
        }
        res += sub;
        return res;
    }
};
