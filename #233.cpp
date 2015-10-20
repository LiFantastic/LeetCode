/*============================================================
Problem: Number of Digit One
==============================================================
Given an integer n, count the total number of digit 1 appearing 
in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 
1, 10, 11, 12, 13.
============================================================*/
class Solution {
public:
    int countDigitOne(int n) {
    int res = 0;
    int i;
    for (i=1; i<=n/10; i*=10)
        res += (n/i + 8) / 10 * i + (n/i % 10 == 1) * (n%i + 1);
    res += (n/i + 8) / 10 * i + (n/i % 10 == 1) * (n%i + 1);
    return res;
    }
};