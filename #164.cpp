/*============================================================
Problem: Maximum Gap
==============================================================
Given an unsorted array, find the maximum difference between 
the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative 
integers and fit in the 32-bit signed integer range.
============================================================*/
// O(NlogN) solution is trival, O(N) solution:
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.empty() || nums.size() == 1) return 0;
        int n = nums.size();
        int minAll = *min_element(nums.begin(), nums.end());
        int maxAll = *max_element(nums.begin(), nums.end());
        // type conversion!!!
        double gap = ((double)(maxAll - minAll)) / (n - 1);
        // compute min and max element for each bucket
        vector<int> minV(n-1, INT_MAX);
        vector<int> maxV(n-1, INT_MIN);
        for (int i=0; i<n; i++) {
            if (nums[i] != maxAll) {// the bktId of maxAll will fall out of bucket range
                int bktId = (int)((nums[i]-minAll)/gap);
                minV[bktId] = min(minV[bktId], nums[i]);
                maxV[bktId] = max(maxV[bktId], nums[i]);
            }
        }
        int res = 0;
        int preMax = maxV[0];
        for(int i=1; i<n-1; i++) {
            if (minV[i]!=INT_MAX) {
                res = max(res, minV[i]-preMax);
                preMax = maxV[i];
            }
        }
        res = max(res, maxAll-preMax);
        return res;
    }
};