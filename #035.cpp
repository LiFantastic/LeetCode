/*============================================================
Problem: Search Insert Position
==============================================================
Given a sorted array and a target value, return the index if 
the target is found. If not, return the index where it would 
be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
============================================================*/
class Solution {
private:
    int binarySearch(vector<int>& A, int n, int target) {
        int left = 0, right = n-1;  // [left, right] covers target
        while (left <= right) {
            int mid = left+(right-left)/2;
            if (A[mid] == target) 
                return mid;
            else if (A[mid] > target) 
                right = mid-1;
            else
                left = mid+1;
        }
        return left;
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        return binarySearch(nums, n, target);
    }
};