/*============================================================
Problem: Palindrome Number
==============================================================
Determine whether an integer is a palindrome. Do this without 
extra space.
============================================================*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)
            return false;
        if (x==0)
            return true;
        int base=1, tmp=x;
       	
        while (tmp/base >= 10)
            base *= 10;
            
        while (tmp) {
            int leftDigit = tmp / base;
            int rightDigit = tmp % 10;
            if (leftDigit != rightDigit)
                return false;
            tmp -= base*leftDigit;
            base /= 100;
            tmp /= 10;
        }
        return true;
    }
};