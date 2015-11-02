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
        int left=0; int right=height.size()-1;
        int res=0, maxleft=0, maxright=0;
        while (left<=right) {
            if (height[left]<=height[right]) {
                maxleft = max(maxleft, height[left]);
                res += maxleft-height[left];
                left++;
            }
            else{
                maxright = max(maxright, height[right]);
                res+=maxright-height[right];
                right--;
            }
        }
        return res;
    }
};
