/*============================================================
Problem: Maximal Rectangle
==============================================================
Given a 2D binary matrix filled with 0's and 1's, find the 
largest rectangle containing all ones and return its area.
============================================================*/
class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
    	if(matrix.empty()) return 0;
    	const int m = matrix.size();
    	const int n = matrix[0].size();
    	int left[n], right[n], height[n];
    	fill_n(left, n, 0); 
    	fill_n(right, n, n);  // can only use fill_n rather than memset
    	fill_n(height, n, 0);
    	int maxArea = 0;
    	for(int i=0; i<m; i++) {
        	int curLeft=0, curRight=n;
        	for (int j=0; j<n; j++) { // compute left (from left to right)
            	if (matrix[i][j]=='1') left[j] = max(left[j], curLeft);
            	else {left[j]=0; curLeft=j+1;}
        	}
        	for (int j=n-1; j>=0; j--) {  // compute right (from right to left)
            	if (matrix[i][j]=='1') right[j] = min(right[j], curRight);
            	else {right[j]=n; curRight=j;}
       		}
        	for (int j=0; j<n; j++) {  // compute height and the area of rectangle (can do this from either side)
            	if (matrix[i][j]=='1') maxArea = max(maxArea,(right[j]-left[j])*(++height[j]));
            	else height[j]=0;
        	}
    	}
    	return maxArea;
	}
};