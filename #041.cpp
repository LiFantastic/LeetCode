/*============================================================
Problem: First Missing Positive
==============================================================
Given an unsorted integer array, find the first missing 
positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
============================================================*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n<1) return 1;
        
        int pos=0;
        while (pos<n) {  // put each num[i] into position num[i]-1
            if (nums[pos]>0 && nums[pos] != pos+1 && nums[pos]-1<n && nums[pos]!=nums[nums[pos]-1])
                swap(nums[pos],nums[nums[pos]-1]);
            else
                pos++;
        }
        for (int i=0; i<n; i++) {   
            if (i+1 != nums[i])
                return i+1;   
        } 
        return n+1;
    }
};