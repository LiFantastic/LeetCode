/*============================================================
Problem: Find Minimum in Rotated Sorted Array II
==============================================================
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Suppose a sorted array is rotated at some pivot unknown to you 
beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.
The array may contain duplicates.
============================================================*/
class Solution {
    int binarySearch(vector<int>::iterator begin, vector<int>::iterator end) {  // [begin, end)
        if (end-begin<=0) return INT_MAX;
        
        vector<int>::iterator mid = begin+(end-begin)/2;
        
        if (*begin < *mid) return min(*begin, binarySearch(mid+1, end));
        else if (*begin == *mid) {
            while (begin<mid && *begin==*mid) begin++;
            if (begin==mid) return min(*mid, binarySearch(mid+1, end));
            else  return min(*mid, binarySearch(begin, mid));
        }
        else return min(*mid, binarySearch(begin, mid));
    }
public:
    int findMin(vector<int>& nums) {
        return binarySearch(nums.begin(), nums.end());
    }
};