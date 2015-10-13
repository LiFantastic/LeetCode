/*============================================================
Problem: Binary Tree Level Order Traversal II
==============================================================
Given a binary tree, return the bottom-up level order traversal 
of its nodes' values. (ie, from left to right, level by level 
from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
    vector<vector<int>> res;

    void traverse(int level, TreeNode *p) {
        if (p == NULL) return;
            
        if (res.size() > level)
        	res[level].push_back(p->val);
        else {
            vector<int> tmp(1, p->val);
            res.push_back(tmp);
        }
        traverse(level+1, p->left);
        traverse(level+1, p->right);
    }
public:    
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        traverse(0, root);
        
        reverse(res.begin(), res.end());    
        return res;
    }
};