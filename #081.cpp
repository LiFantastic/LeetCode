/*============================================================
Problem: Search in Rotated Sorted Array II
==============================================================
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.
============================================================*/
class Solution {
private:
    bool search(vector<int> &nums, int left, int right, int target) {  // [left, right]: search area
        if (left > right)  return false;
        if (left == right) return nums[left]==target;
        
        int mid = (left + right) / 2;
        
        if (nums[mid] == target) return true;

        if (nums[left] < nums[right]) {  // [left, right] in normal ascending order
            if (target < nums[left] || target > nums[right]) return false;
            else {
                if (nums[mid] > target)  // left part: [left, mid-1]
                    return search(nums, left, mid-1, target);
                else  // right part: [mid+1, right]
                    return search(nums, mid+1, right, target);    
            }
        } 
        else if (nums[left] > nums[right])
            return search(nums, left, mid-1, target) ? true : search(nums, mid+1, right, target);    
        else {  // deal with duplicates
            while (left<right && nums[left]==nums[right]) left++;
            return search(nums, left, right, target);
        }
    }
public:
    bool search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size()-1, target);
    }
};