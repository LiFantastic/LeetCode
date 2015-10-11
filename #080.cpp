/*============================================================
Problem: Remove Duplicates from Sorted Array II
==============================================================
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five 
elements of nums being 1, 1, 2, 2 and 3. It doesn't matter 
what you leave beyond the new length.
============================================================*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int newSize=0, n=nums.size();
        
        for (int i=0; i<n; i++) {
            if (i==0 || i==1)
                nums[newSize++] = nums[i];
            else if (nums[i] != nums[newSize-2])
                nums[newSize++] = nums[i];
        }
        return newSize;
    }
};