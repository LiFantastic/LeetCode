/*============================================================
Problem: Single Number II
==============================================================
Given an array of integers, every element appears three times 
except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could 
you implement it without using extra memory?
============================================================*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one=0, two=0, three=0;
       
        for(int i=0; i<nums.size(); i++) {
            three =  two & nums[i];
            two = two | one & nums[i];
            one = one | nums[i];
            // remove all that appears three times
            one = one & ~three;
            two = two & ~three;
        }
         return one;
    }
};