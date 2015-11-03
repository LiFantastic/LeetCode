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
  vector<vector<int>> res;
  vector<int> tmp;
private:
    void dfs(vector<int>& nums, int index) {
        res.push_back(tmp);  // add this subset

        for (int i=index; i<nums.size(); i++) {
            tmp.push_back(nums[i]);
            dfs(nums, i+1);
            tmp.pop_back();
        }
    }
public:    
    vector<vector<int> > subsets(vector<int>& nums) {
        if (nums.size()==0) return res;
        sort(nums.begin() , nums.end()); // sort
        dfs(nums, 0);
        return res;
    }
};