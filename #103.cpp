/*============================================================
Problem: Binary Tree Zigzag Level Order Traversal
==============================================================
Given a binary tree, return the zigzag level order traversal 
of its nodes' values. (ie, from left to right, then right to 
left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
    
    void levelTraverse(int level, TreeNode* p) {
        if (p==NULL) return;
        if (res.size() > level)
            res[level].push_back(p->val);
        else
            res.push_back(vector<int>(1, p->val));
            
        levelTraverse(level+1, p->left);
        levelTraverse(level+1, p->right);
        
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        levelTraverse(0, root);
        for (int i=1; i<res.size(); i+=2)
            reverse(res[i].begin(), res[i].end());
        return res;
    }
};