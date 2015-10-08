/*============================================================
Problem: Search in Rotated Sorted Array
==============================================================
Suppose a sorted array is rotated at some pivot unknown to you 
beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array 
return its index, otherwise return -1.

You may assume no duplicate exists in the array.
============================================================*/
class Solution {
private:
    int search(vector<int> &nums, int left, int right, int target) {  // search range [left, right]
        if (left > right) return -1;  // left > right, not exist
        int mid = left + (right - left) / 2;  // avoid overflow
        if (nums[mid] == target) return mid;
        if (nums[left] <= nums[right]) {  // [left...right] mus be in ascending order in this case, thus apply normal binary search
            if (target < nums[left] || target > nums[right])
                return -1;
            else {
                if (nums[mid] > target)  // search left part [left, mid-1]
                    return search(nums, left, mid-1, target);    
                else  // search right part [mid+1, right]
                    return search(nums, mid+1, right, target);    
            }
        } 
        else {  // recursive
            int s1 = search(nums, left, mid-1, target);    
            return (s1 == -1) ? search(nums, mid+1, right, target) : s1;    
        }
    }
public:
    int search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size()-1, target);
    }
};