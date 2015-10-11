/*============================================================
Problem: Climbing Stairs
==============================================================
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many 
distinct ways can you climb to the top?
============================================================*/
class Solution {
public:
    int climbStairs(int n) {
        int twoLess=1,  oneLess=2, current;
        
        if (n<=2) return n;            
        for (int i=2; i<n; i++) {
            current = oneLess + twoLess;
            twoLess = oneLess;
            oneLess = current;
        }
        return current;
    }
};