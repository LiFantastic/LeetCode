/*============================================================
Problem: Divide Two Integers
==============================================================
Divide two integers without using multiplication, division 
and mod operator.

If it is overflow, return MAX_INT.
============================================================*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0 || divisor == 0)
            return 0;

        bool sign = true;
        if ((dividend>0 && divisor<0) || (dividend<0 && divisor>0))
            sign = false;
        
        long a = dividend;
        long b = divisor;
        a = abs(a);
        b = abs(b);

        if (b > a)
            return 0;

        long sum, count, res=0;

        while (a>=b) {
            count = 1;
            sum = b;
            while ((sum<<1) < a) {
                sum <<= 1;
                count <<= 1;
            }
            a -= sum;
            res += count;
            if (res > INT_MAX)
                return sign ? INT_MAX : INT_MIN;
        }
        return sign ? res : -res;
    }
};