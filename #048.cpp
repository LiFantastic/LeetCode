/*============================================================
Problem: Rotate Image
==============================================================
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
============================================================*/
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int i, j, temp;
        int n = matrix.size();
        for(i=0; i<n/2; i++) {
            for (j=i; j<n-1-i; j++) {
                temp = matrix[j][n-i-1];
                matrix[j][n-i-1] = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = temp;
            }
        }
    }
};  // done by math calculation of the indecies