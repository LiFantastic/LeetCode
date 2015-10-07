/*============================================================
Problem: 3Sum Closest
==============================================================
Given an array S of n integers, find three integers in S such 
that the sum is closest to a given number, target. Return the 
sum of the three integers. You may assume that each input 
would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
============================================================*/
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());        
        int res = target>=0 ? INT_MAX : INT_MIN;
        
        for(int i=0; i<num.size(); i++) {
        	if (i>0 && num[i]==num[i-1]) // ignore duplicates 
        		continue;
            int j = i + 1;
            int k = num.size() - 1;
            while (j < k) {
            	if (j>i+1 && num[j]==num[j-1]) { // ignore duplicates 
					j++;
					continue;
				}
				if (k<num.size()-1 && num[k]==num[k+1]) { // ignore duplicates
					k--;
					continue;
				}
                int sum = num[i] + num[j] + num[k];
                if (abs(sum-target) < abs(res-target))
                	res = sum;                                         
                if (res==target)
                    return res;
                    
                if (sum > target)
                    k--;
                else
                    j++;
            }
        }
        
        return res;
    }
};