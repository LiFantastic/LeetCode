/*============================================================
Problem: Binary Tree Level Order Traversal
==============================================================
Given a binary tree, return the level order traversal of its 
nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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

    void levelTraverse(int level, TreeNode *p) {
        if (p == NULL) return;

        if (res.size() > level)
            res[level].push_back(p->val);
        else
            res.push_back(vector<int>(1, p->val));
        levelTraverse(level+1, p->left);
        levelTraverse(level+1, p->right);
    }
public:    
    vector<vector<int> > levelOrder(TreeNode *root) {
        levelTraverse(0, root);
        return res;
    }
};