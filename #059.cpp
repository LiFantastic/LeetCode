/*============================================================
Problem: Spiral Matrix II
==============================================================
Given an integer n, generate a square matrix filled with 
elements from 1 to n2 in spiral order.

For example,
Given n = 3,
You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
============================================================*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int x1 = 0, y1 = 0, x2 = n-1, y2 = n-1, num = 0;
        vector<vector<int>> res(n, vector<int>(n,0));
        while (x1<=x2 && y1<=y2) {
            //up row
            for (int i=y1; i<=y2; i++) res[x1][i] = ++num;
            //right column
            for (int i=x1+1; i<=x2; i++) res[i][y2] = ++num;
            //bottom row
            if (x2!=x1) {
            	for(int i=y2-1; i>=y1; i--) 
            		res[x2][i] = ++num;
            }
            //left column
            if (y1!=y2) {
            	for(int i=x2-1; i>x1; i--) 
            		res[i][y1] = ++num;
            }
            x1++, y1++, x2--, y2--;
        }
        return res;
    }
};