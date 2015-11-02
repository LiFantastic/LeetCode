/*============================================================
Problem: Subsets
==============================================================
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
============================================================*/
class Solution {
private:
	vector<int> tmp;
	vector<vector<int>> res;
    
	void dfs(vector<int>& nums, int index) {
    	if (index == nums.size()) {
      		res.push_back(tmp);
      		return;
    	}
    	// don't add nums[index]
    	dfs(nums, index+1);

    	// add nums[index]
    	tmp.push_back(nums[index]);
    	dfs(nums, index+1);
    	tmp.pop_back();
  	}
public:
	vector<vector<int>> subsets(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	dfs(nums, 0);
    	return res;
	}
};