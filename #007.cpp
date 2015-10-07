/*============================================================
Problem: Reverse Integer
==============================================================
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Assume that your function returns 0 when the reversed integer 
overflows.
============================================================*/
class Solution {
public:
    int reverse(int x) {
        bool sign = x > 0 ? true : false;
        long temp = x;
        long result = 0;
        temp = temp > 0 ? temp : -temp;
        while(temp) {
            result *= 10;
            result += temp % 10;
            temp /= 10;
        }
        if (result > INT_MAX || result < INT_MIN)
            return 0;
        else {
            if(sign)
                return result;
            else
                return -result;
        }
    }
};