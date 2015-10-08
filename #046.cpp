/*============================================================
Problem: Permutations
==============================================================
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
============================================================*/
class Solution {
private:
	vector<vector<int> > res;

	void dfs(vector<int>& nums, int cur) {
		if (cur == nums.size())
		    res.push_back(nums);
		else {
			for (int i=cur; i<nums.size(); i++) {
				swap(nums[cur], nums[i]);
				dfs(nums, cur+1);
				swap(nums[cur], nums[i]);
			}
		}
	}
public:
    vector<vector<int>> permute(vector<int> &nums) {
		dfs(nums, 0);
		return res;
    }
};