/*============================================================
Problem: Subsets II
==============================================================
Given a collection of integers that might contain duplicates, 
return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
============================================================*/
class Solution {
	vector<vector<int>> res;
	vector<int> tmp;
private:
    void dfs(vector<int>& nums, int index) {
        res.push_back(tmp);  // add this subset

        for (int i=index; i<nums.size(); i++) {
            if (i!=index && nums[i]==nums[i-1]) continue;  // select duplicates only once in every layer
            tmp.push_back(nums[i]);
            dfs(nums, i+1);
            tmp.pop_back();
        }
    }
public:    
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        if (nums.size()==0) return res;
        sort(nums.begin() , nums.end()); // sort
        dfs(nums, 0);
        return res;
    }
};