/*============================================================
Problem: Binary Tree Right Side View
==============================================================
Given a binary tree, imagine yourself standing on the right 
side of it, return the values of the nodes you can see ordered 
from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
============================================================*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> res;
    
    void dfs(TreeNode *p, int l) {
        if (p==NULL) return;
        if (l==res.size()) res.push_back(p->val);
        dfs(p->right, l+1);
        dfs(p->left, l+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};