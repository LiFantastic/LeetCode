/*============================================================
Problem: Add Binary
==============================================================
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
============================================================*/
class Solution {
public:
    string addBinary(string a, string b) {
        string aReverse = string(a);
        string bReverse = string(b);
        
        reverse(aReverse.begin(), aReverse.end());
        reverse(bReverse.begin(), bReverse.end());
        
        int la = a.size(), lb = b.size();
        int i = 0, carry = 0, aNum, bNum, cNum;
        string cReverse = "";
        
        while (i<la && i<lb) {
            aNum = aReverse[i] - '0';
            bNum = bReverse[i] - '0';
            cNum = aNum+bNum+carry;
            if (cNum>=2) {
                cNum -= 2;
                carry = 1;
            }
            else
                carry = 0;
                
            cReverse += (cNum+'0');
            i++;
        }
        while (i<la) {
            aNum = aReverse[i] - '0';
            cNum = aNum+carry;
            if (cNum>=2) {
                cNum -= 2;
                carry = 1;
            }
            else
                carry = 0;
            cReverse += (cNum+'0');
            i++;
        }
        while (i<lb) {
            bNum = bReverse[i] - '0';
            cNum = bNum+carry;
            if (cNum>=2) {
                cNum -= 2;
                carry = 1;
            }
            else
                carry = 0;
            cReverse += (cNum+'0');
            i++;
        }
        
        if (carry==1)
            cReverse += '1';
        
        reverse(cReverse.begin(), cReverse.end());
        
        return cReverse;
    }
};