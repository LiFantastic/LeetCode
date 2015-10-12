/*============================================================
Problem: Largest Rectangle in Histogram
==============================================================
Given n non-negative integers representing the histogram's bar 
height where the width of each bar is 1, find the area of 
largest rectangle in the histogram.
For example,
Given height = [2,1,5,6,2,3],
return 10. (5+5)
============================================================*/
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> indexStack;  
        indexStack.push(-1);
        height.push_back(0);
        int res = 0;  
        for (int i=0; i<height.size(); i++) {  
            while (indexStack.top()!=-1 && height[i]<height[indexStack.top()]) {
                int tmp = indexStack.top();
                indexStack.pop();
                res = max(res, height[tmp]*(i-indexStack.top()-1));
            }
            indexStack.push(i);
        }
        return res;  
    } 
};