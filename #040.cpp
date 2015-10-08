/*============================================================
Problem: Combination Sum II
==============================================================
Given a collection of candidate numbers (C) and a target 
number (T), find all unique combinations in C where the 
candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in 
non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
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
        	    if (i>index && sorted[i]==sorted[i-1])  // pruning duplicates
        	        continue;
        		tmpSum += sorted[i];
            	tmp.push_back(sorted[i]);
            	dfs(target, i+1);
            	tmpSum -= sorted[i];
            	tmp.pop_back();
        	}
    	}
  	}
public:
	vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    	sorted = vector<int>(candidates);
    	sort(sorted.begin(), sorted.end(), greater<int>());
    
    	tmpSum = 0;
    	tmp.clear();
    	dfs(target, 0);
    	return res;
  	}
};