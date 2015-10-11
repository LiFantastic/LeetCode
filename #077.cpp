/*============================================================
Problem: Combinations
==============================================================
Given two integers n and k, return all possible combinations 
of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
============================================================*/
class Solution {
private:
    vector<int> tmp;
    vector<vector<int>> res;
    int n;
    int k;

    void dfs(int count, int index) {
        if (count == k) {
            res.push_back(tmp);
            return;
        }
        for (int i=index; i<n; i++) {
            tmp.push_back(i+1);
            dfs(count+1, i+1);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
    	this->n = n;
    	this->k = k;
        dfs(0, 0);
        return res;
    }
};