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
	vector<int> tmp;
	vector<bool> notused;

	void dfs(vector<int>& nums) {
		if (tmp.size() == nums.size()) {
		    res.push_back(tmp);
		    return;
		}
		for (int i=0; i<nums.size(); i++) {
			if (notused[i]) {
			    notused[i] = false;
			    tmp.push_back(nums[i]);
				dfs(nums);
				notused[i] = true;
				tmp.pop_back();
			}
		}
	}
public:
    vector<vector<int>> permute(vector<int> &nums) {
        notused = vector<bool>(nums.size(), true);
		dfs(nums);
		return res;
    }
};