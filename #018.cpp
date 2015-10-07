/*============================================================
Problem: 4Sum
==============================================================
Given an array S of n integers, are there elements a, b, c, 
and d in S such that a + b + c + d = target? Find all unique 
quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending 
order. (ie, a ≤ b ≤ c ≤ d)

The solution set must not contain duplicate quadruplets.

For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)
============================================================*/
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int N = num.size();
        vector<vector<int> > res;
        
        for (int i=0; i<N; i++) {
            if (i>0 && num[i]==num[i-1])
                continue;
            if (num[i]+num[N-3]+num[N-2]+num[N-1] < target)
                continue;  // simple pruning but pretty efficient
                
            for (int j=i+1; j<N; j++) {
                if (j>i+1 && num[j] == num[j-1])
                    continue;
                if (num[i]+num[j]+num[N-2]+num[N-1] < target)
                    continue; // simple pruning but pretty efficient
                    
                int k = j + 1;
                int l = N - 1;
                while (k < l) {
                    if (k>j+1 && num[k] == num[k-1]) {
                        k++;
                        continue;
                    }
                    if (l<N-1 && num[l] == num[l+1]) {
                        l--;
                        continue;
                    }
                    int sum = num[i] + num[j] + num[k] + num[l];
                    if (sum == target) {
                        vector<int> tmp = {num[i], num[j], num[k], num[l]};
                        res.push_back(tmp);
                        k++;
                    }
                    else if (sum < target)
                        k++;
                    else
                        l--;                        
                }
            }
        }
        return res;
    }
};