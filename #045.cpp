/*============================================================
Problem: Jump Game II
==============================================================
Given an array of non-negative integers, you are initially 
positioned at the first index of the array.

Each element in the array represents your maximum jump length 
at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. 
(Jump 1 step from index 0 to 1, then 3 steps to the last index.)
============================================================*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int curMax = 0;  // max range covered by nums[0]~nums[i]
        int curRch = 0;  // the max range that start from nums[0] and after res jumps
        int n = nums.size();
        
        for (int i=0; i<n; i++) {
            if (curRch < i) {
                res++;
                curRch = curMax;
            }
            assert(curRch>=i);  // otherwise cant reach (we assume we can)
            curMax = max(curMax, nums[i]+i);
        }
        return res;
    }
};