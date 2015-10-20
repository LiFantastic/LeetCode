/*============================================================
Problem: House Robber II
==============================================================
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found 
himself a new place for his thievery so that he will not get too 
much attention. This time, all houses at this place are arranged 
in a circle. That means the first house is the neighbor of the 
last one. Meanwhile, the security system for these houses remain 
the same as for those in the previous street.

Given a list of non-negative integers representing the amount 
of money of each house, determine the maximum amount of money 
you can rob tonight without alerting the police.
============================================================*/
class Solution {
private:
    int robWithoutCircle(vector<int>& nums, int l, int r) {
        int rob = 0, notrob = 0;
        for (int i = l; i <= r; i++) {
            int prerob = rob;
            rob = notrob+nums[i];
            notrob = max(prerob, notrob);
            
        }
        return max(rob, notrob);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        return max(robWithoutCircle(nums, 0, n-2), robWithoutCircle(nums, 1, n-1));
    }
};