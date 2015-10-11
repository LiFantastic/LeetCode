/*============================================================
Problem: Pow(x, n)
==============================================================
Implement pow(x, n).
============================================================*/
class Solution {
private:
    double power(double x, long n) {
        if (n == 0)
            return 1;
        double sqareRoot = power(x, n>>1);      
        if (n&1)
            return sqareRoot*sqareRoot*x;
        else
            return sqareRoot*sqareRoot;
    }
public:    
    double myPow(double x, int n) {
        long N = n;
        if (N < 0)
            return 1.0 / power(x, -N);
        else
            return power(x, N);       
    }
};