/*============================================================
Problem: Balanced Binary Tree
==============================================================
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as 
a binary tree in which the depth of the two subtrees of every 
node never differ by more than 1.
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
    int checkHeight(TreeNode* p) {  
    // return the height of subtree if it is banlanced, otherwise -1 for early pruning
        if (p==NULL) return 0;
        int leftHeight = checkHeight(p->left);
        if (leftHeight==-1) return -1;  // pruning
        int rightHeight = checkHeight(p->right);
        if (rightHeight==-1) return -1;  // pruning
        
        int heightDiff = abs(leftHeight-rightHeight);
        if (heightDiff>1) return -1;
        else return max(leftHeight, rightHeight)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (checkHeight(root)==-1) return false;
        else return true;
    }
};
