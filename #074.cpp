/*============================================================
Problem: Search a 2D Matrix
==============================================================
Write an efficient algorithm that searches for a value in an 
m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer 
of the previous row.
For example,

Consider the following matrix:
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
============================================================*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m==0) return false;
        int n = matrix[0].size();
        if (n==0) return false;
        
        int i, j, mid, left = 0, right = m*n-1;
        
        while (left <= right) {  // binary search
            mid = left+(right-left)/2;
            i = mid/n;
            j = mid-i*n;  // calculate row, col by index
            if (matrix[i][j] > target)
                right = mid-1;
            else if (matrix[i][j] < target)
                left = mid+1;
            else
                return true;
        }
        return false;
    }
};