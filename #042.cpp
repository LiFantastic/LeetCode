/*============================================================
Problem: Trapping Rain Water
==============================================================
Given n non-negative integers representing an elevation map 
where the width of each bar is 1, compute how much water it 
is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
============================================================*/
class Solution {
public:
    int trap(vector<int>& height) {
        int secHight = 0;
        int left =0, right = height.size()-1;
        int trapArea = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                secHight = max(height[left], secHight);
                trapArea += secHight-height[left];
                left++;
            }
            else {
                secHight = max(height[right], secHight);
                trapArea += secHight-height[right];
                right--;
            }
        }
        return trapArea;      
    }
};
