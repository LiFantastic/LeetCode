/*============================================================
Problem: Binary Tree Maximum Path Sum
==============================================================
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes f
rom some starting node to any node in the tree along the parent-child 
connections. The path does not need to go through the root.

For example:
Given the below binary tree,
       1
      / \
     2   3
Return 6.
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
    int maxSum = INT_MIN;

    int maxPathAt(TreeNode* p) {
        if (p==NULL) return 0;
        
        int leftSum = maxPathAt(p->left);
        int rightSum = maxPathAt(p->right);
        
        maxSum = max(maxSum, leftSum+rightSum+p->val);
        return max(0, max(leftSum, rightSum)+p->val);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        maxPathAt(root);
        return maxSum;
    }
};