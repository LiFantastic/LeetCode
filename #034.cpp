/*============================================================
Problem: Search for a Range
==============================================================
Given a sorted array of integers, find the starting and ending 
position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
============================================================*/
class Solution {
private:
    int findPos(vector<int>& A, int left, int right, int key, bool findLeft) {  // search range [left, right]
        if (left > right) return -1;
        int mid = (left + right) / 2;

        if (A[mid] == key) {
            if (findLeft) {
                while (mid>=0 && A[mid]==key) mid--;
                return mid+1;
            }
            else {
                while (mid<A.size() && A[mid]==key) mid++;
                return mid-1;
            }
        }
        else if (A[mid] < key)  // search right part
            return findPos(A, mid+1, right, key, findLeft);
        else  // search left part
            return findPos(A, left, mid-1, key, findLeft);       
    }
public:    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        int leftPos = findPos(nums, 0, n - 1, target, true);
        int rightPos = findPos(nums, 0, n - 1, target, false);
        
        vector<int> ret = {leftPos, rightPos};
        return ret;
    }
};