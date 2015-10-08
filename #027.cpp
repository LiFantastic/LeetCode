/*============================================================
Problem: Remove Element
==============================================================
Given an array and a value, remove all instances of that value 
in place and return the new length.

The order of elements can be changed. It doesn't matter what 
you leave beyond the new length.
============================================================*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int remain=0;  // the remain count uptill now
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]!=val) {
            	if (remain!=i)
            		nums[remain] = nums[i];
            	remain++;
                continue;
            }
        }
        return remain;
    }
};