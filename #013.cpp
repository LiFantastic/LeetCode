/*============================================================
Problem: Integer to Roman
==============================================================
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
============================================================*/
class Solution {
public:
    string intToRoman(int num) {
        int vals[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        string val2Str[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        
        int tmp = num;
        string res = "";
        for (int i=0; i<13; i++) {
            while (tmp >= vals[i]) {
                tmp -= vals[i];
                res += val2Str[i];
            }
        }
        return res;
    }
};
