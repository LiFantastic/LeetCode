/*============================================================
Problem: Sqrt(x)
==============================================================
Implement int sqrt(int x).

Compute and return the square root of x.
============================================================*/
class Solution {
public:
    int mySqrt(int x) {
        if (x ==0)
            return 0;
        double pre, cur=1;
        do {
            pre = cur;
            cur = x / (2 * pre) + pre / 2;
        } while (abs(cur - pre) > 0.1);
        // Newton-Raphson method
        return int(cur);
    }
};