/*============================================================
Problem: Minimum Depth of Binary Tree
==============================================================
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest 
path from the root node down to the nearest leaf node.
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
    int calcHeight(TreeNode* p) {
        if (p==NULL) return 0;
        
        if (p->left==NULL) return calcHeight(p->right)+1;
        else if (p->right==NULL) return calcHeight(p->left)+1;
        else return min(calcHeight(p->left), calcHeight(p->right))+1;
    }
public:
    int minDepth(TreeNode* root) {
        return calcHeight(root);
    }
};
