/*============================================================
Problem: Combination Sum III
==============================================================
Find all possible combinations of k numbers that add up to a 
number n, given that only numbers from 1 to 9 can be used and 
each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.

Example 1:
Input: k = 3, n = 7
Output:
[[1,2,4]]

Example 2:
Input: k = 3, n = 9
Output:
[[1,2,6], [1,3,5], [2,3,4]]
============================================================*/
class Solution {
private:
	vector<vector<int>> res;
    vector<int> tmp;

	void backtrack(int start, int k, int target){
    	if (target==0 && k==0){
        	res.push_back(tmp);
        	return;
    	}
    	for (int i=start; i<=min(10-k, target); i++){
        	tmp.push_back(i);
        	backtrack(i+1,k-1,target-i);
        	tmp.pop_back();
    	}
	}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
    	
    	backtrack(1, k, n);
   		return res;
	}
};