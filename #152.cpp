/*============================================================
Problem: Maximum Product Subarray
==============================================================
Find the contiguous subarray within an array (containing at 
least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
============================================================*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
    	int n = nums.size(), maxValue = INT_MIN;
    	int headValue = 1;  // multiply elements from head to tail
    	int tailValue = 1;  // multiply elements from tail to head
    	for (int i=0; i<n; i++) {
        	headValue *= nums[i];
        	tailValue *= nums[n-1-i];
        	maxValue = max(maxValue, max(headValue, tailValue));
        	if (headValue==0) headValue = 1;  // if element = 0, array is divided, reset the product = 0.
        	if (tailValue==0) tailValue = 1;
    	}
    	return maxValue;
	}
};