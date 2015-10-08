/*============================================================
Problem: Combination Sum
==============================================================
Given a set of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in 
non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
============================================================*/
class Solution {
private:
	vector<vector<int>> res;
  	vector<int> sorted;
  	vector<int> tmp;
  	int tmpSum;
  
  	void dfs(int target, int index) {
    	if (tmpSum == target) {
        	reverse(tmp.begin(), tmp.end());
        	res.push_back(tmp);
        	reverse(tmp.begin(), tmp.end());
        	return;
    	}
    	else if (tmpSum > target) // no need to continue search, pruning
    	    return;
    	else {
        	for (int i=index; i<sorted.size(); i++) {
        		tmpSum += sorted[i];
            	tmp.push_back(sorted[i]);
            	dfs(target, i);
            	tmpSum -= sorted[i];
            	tmp.pop_back();
        	}
    	}
  	}
public:
	vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    	sorted = vector<int>(candidates);
    	sort(sorted.begin(), sorted.end(), greater<int>());
    
    	tmpSum = 0;
    	tmp.clear();
    	dfs(target, 0);
    	return res;
  	}
};