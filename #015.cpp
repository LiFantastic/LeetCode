/*============================================================
Problem: 3Sum
==============================================================
Given an array S of n integers, are there elements a, b, c in 
S such that a + b + c = 0? Find all unique triplets in the 
array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. 
(ie, a ≤ b ≤ c) The solution set must not contain duplicate 
triplets.

For example, given array S = {-1 0 1 2 -1 -4},
A solution set is:
(-1, 0, 1)
(-1, -1, 2)
============================================================*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > res;
        sort(num.begin(), num.end());
        int i, j, k;
        for (i=0; i<num.size(); i++) {
            if (i>0 && num[i]==num[i-1]) // ignore duplicates
                continue;
			
			j = i+1;
			k = num.size()-1;
			
			while (j<k) {
			    if (j>i+1 && num[j]==num[j-1]) { // ignore duplicates 
					j++;
					continue;
				}
				if (k<num.size()-1 && num[k]==num[k+1]) { // ignore duplicates
					k--;
					continue;
				}
				int sum = num[i] + num[j] + num[k];
				if (sum>0)  k--;
				else if (sum<0) j++;
				else {
					int tmp[3] = {num[i], num[j], num[k]}; 
					res.emplace_back(tmp, tmp+3);
					j++;
				}
			}
		}
		return res;
    }
};